class Account:
    def __init__(self, an, hn, p, b, dw):
        self.__account_no = an
        self.holder_name = hn
        self.__pin = p
        self.__balance = b
        self.__daily_withdrawn = dw
        self.__transaction_log = []
        self.__next_tx_id = 1

    def verify_pin(self, pin):
        return pin == self.__pin

    def get_account_no(self):
        return self.__account_no

    def get_balance(self):
        return self.__balance

    def get_transactions(self):
        return list(self.__transaction_log)

    def _log(self, typ, amount, balance_after, meta=None):
        tx_id = self.__next_tx_id
        self.__next_tx_id += 1
        entry = {"id": tx_id, "type": typ, "amount": amount, "balance_after": balance_after}
        if meta is not None:
            entry["meta"] = meta
        self.__transaction_log.append(entry)
        return entry

    def transfer(self, typ, amount=0, target=None, meta=None):
        if typ == "WITHDRAW":
            if amount <= 0:
                return False
            if amount > self.__balance:
                return False
            self.__balance -= amount
            self.__daily_withdrawn += amount
            self._log("WITHDRAW", amount, self.__balance, meta)
            return True

        elif typ == "DEPOSIT":
            if amount <= 0:
                return False
            self.__balance += amount
            self._log("DEPOSIT", amount, self.__balance, meta)
            return True

        elif typ == "TRANSFER_OUT":
            # target must be another Account instance
            if target is None or not isinstance(target, Account):
                return False
            if amount <= 0:
                return False
            if amount > self.__balance:
                return False
            self.__balance -= amount
            # log outgoing
            self._log("TRANSFER_OUT", amount, self.__balance, {"to": target.get_account_no()})
            # credit the target by using its transfer interface (avoids touching private attrs)
            target.transfer("TRANSFER_IN", amount, meta={"from": self.get_account_no()})
            return True

        elif typ == "TRANSFER_IN":
            if amount <= 0:
                return False
            self.__balance += amount
            self._log("TRANSFER_IN", amount, self.__balance, meta)
            return True

        elif typ == "BALANCE":
            self._log("BALANCE", 0, self.__balance)
            return True

        else:
            return False


def ATM(account):
    an = input("Enter the account number: ")
    try:
        p = int(input("Enter the PIN: "))
    except Exception:
        print("Authentication failed.")
        return
    if an != account.get_account_no() or not account.verify_pin(p):
        print("Authentication failed.")
        return
    print("What do you want to perform?\n1. Withdrawal\n2. Deposit\n3. Transfer Out\n4. Check balance")
    try:
        n = int(input("Enter your choice: "))
    except Exception:
        print("Invalid choice.")
        return

    # use if/elif for compatibility (match/case requires Python 3.10+)
    if n == 1:
        try:
            amt = int(input("Enter amount to withdraw: "))
        except Exception:
            print("ERROR: INVALID_AMOUNT")
            return
        account.transfer("WITHDRAW", amt)
    elif n == 2:
        try:
            amt = int(input("Enter amount to deposit: "))
        except Exception:
            print("ERROR: INVALID_AMOUNT")
            return
        account.transfer("DEPOSIT", amt)
    elif n == 3:
        tgt_an = input("Enter target account number: ")
        tgt_name = input("Enter target holder name: ")
        try:
            amt = int(input("Enter amount to transfer: "))
        except Exception:
            print("ERROR: INVALID_AMOUNT")
            return
        target = Account(tgt_an, tgt_name, 0, 0, 0)
        account.transfer("TRANSFER_OUT", amt, target)
    elif n == 4:
        account.transfer("BALANCE")
    else:
        print("Invalid choice.")


# ----------------- Deterministic dataset & ATM model -----------------

class Bank:
    def __init__(self):
        self.__accounts = {}
        # Embedded deterministic dataset
        self.__add(Account("1001", "ALI RAZA", 1234, 50000, 0))
        self.__add(Account("1002", "AYESHA M RAZA", 2468, 20000, 0))
        self.__add(Account("1003", "HAMZA B ZUBAIR", 1357, 150000, 0))

    def __add(self, account):
        self.__accounts[account.get_account_no()] = account

    def find(self, account_no):
        return self.__accounts.get(account_no)


class ATMDevice:
    DAILY_WITHDRAWAL_CAP = 100000
    WITHDRAW_MIN = 100
    WITHDRAW_MAX = 50000
    PIN_TRIES = 3

    def __init__(self, bank):
        self.bank = bank
        self.cassettes = {5000: 10, 1000: 25, 500: 30, 100: 50}
        self.state = "IDLE"
        self.current_account = None
        self.pin_tries = self.PIN_TRIES

    def __dispense_plan(self, amount):
        # Greedy with limited backtracking on highest denom
        denoms = sorted(self.cassettes.keys(), reverse=True)
        counts = [self.cassettes[d] for d in denoms]

        def try_greedy(avail):
            rem = amount
            plan = {}
            for i, d in enumerate(denoms):
                take = min(rem // d, avail[i])
                if take > 0:
                    plan[d] = take
                    rem -= d * take
            return plan if rem == 0 else None

        plan = try_greedy(counts)
        if plan is not None:
            return plan
        if counts:
            high = counts[0]
            for reduce_by in range(1, high + 1):
                trial = counts[:]
                trial[0] = high - reduce_by
                plan = try_greedy(trial)
                if plan is not None:
                    return plan
        return None

    def __apply_dispense(self, plan):
        for d, c in plan.items():
            self.cassettes[d] -= c

    def authenticate(self):
        tries = self.PIN_TRIES
        an = input("Enter account number: ")
        account = self.bank.find(an)
        if account is None:
            print("Card not recognized (account not found).")
            return None
        while tries > 0:
            try:
                p = int(input("Enter PIN: "))
            except Exception:
                p = -1
            if account.verify_pin(p):
                return account
            tries -= 1
            print("Invalid PIN. Tries left:", tries)
        print("Too many failed attempts. Card ejected.")
        return None

    def withdraw(self, account):
        try:
            amount = int(input("Enter amount to withdraw: "))
        except Exception:
            print("ERROR: INVALID_AMOUNT")
            return
        self._withdraw_amount(account, amount)

    def _withdraw_amount(self, account, amount):
        if amount % 100 != 0:
            print("ERROR AMOUNT_INVALID")
            return
        if amount < self.WITHDRAW_MIN or amount > self.WITHDRAW_MAX:
            print("ERROR AMOUNT_INVALID")
            return
        if account.get_balance() < amount:
            print("ERROR INSUFFICIENT_FUNDS")
            return
        daily = 0
        for t in account.get_transactions():
            if t["type"] == "WITHDRAW":
                daily += t["amount"]
        if daily + amount > self.DAILY_WITHDRAWAL_CAP:
            print("ERROR DAILY_LIMIT_EXCEEDED")
            return
        plan = self.__dispense_plan(amount)
        if plan is None:
            print("ERROR DENOMINATION_UNAVAILABLE")
            return
        if account.transfer("WITHDRAW", amount, meta={"mix": plan}):
            self.__apply_dispense(plan)
            parts = []
            for d in sorted(self.cassettes.keys(), reverse=True):
                n = plan.get(d, 0)
                if n > 0:
                    parts.append(f"{d}x{n}")
            print(f"WITHDRAW_OK {amount} {' '.join(parts)}")

    def deposit(self, account):
        try:
            amount = int(input("Enter amount to deposit: "))
        except Exception:
            print("ERROR: INVALID_AMOUNT")
            return
        if amount <= 0 or amount % 100 != 0:
            print("ERROR: INVALID_AMOUNT")
            return
        if account.transfer("DEPOSIT", amount):
            print("DEPOSIT_OK", amount)

    def _deposit_amount(self, account, amount):
        if amount <= 0 or amount % 100 != 0:
            print("ERROR AMOUNT_INVALID")
            return
        if account.transfer("DEPOSIT", amount):
            print(f"DEPOSIT_OK {amount}")

    def transfer_out(self, account):
        tgt = input("Enter target account number: ")
        target = self.bank.find(tgt)
        if target is None or target.get_account_no() == account.get_account_no():
            print("ERROR: INVALID_TARGET")
            return
        try:
            amount = int(input("Enter amount to transfer: "))
        except Exception:
            print("ERROR: INVALID_AMOUNT")
            return
        if amount <= 0:
            print("ERROR: INVALID_AMOUNT")
            return
        if amount > account.get_balance():
            print("ERROR: INSUFFICIENT_FUNDS")
            return
        if account.transfer("TRANSFER_OUT", amount, target):
            print("TRANSFER_OK", amount, "to:" + target.get_account_no())

    def _transfer_amount(self, account, target_ac_no, amount):
        target = self.bank.find(target_ac_no)
        if target is None or target.get_account_no() == account.get_account_no():
            if target is None:
                print("ERROR TARGET_UNKNOWN")
            else:
                print("ERROR TARGET_SAME_AS_SOURCE")
            return
        if amount <= 0:
            print("ERROR AMOUNT_INVALID")
            return
        if amount > account.get_balance():
            print("ERROR INSUFFICIENT_FUNDS")
            return
        if account.transfer("TRANSFER_OUT", amount, target):
            print(f"TRANSFER_OK {amount} to:{target.get_account_no()}")

    def balance(self, account):
        if account.transfer("BALANCE"):
            print(f"BALANCE {account.get_balance()}")

    def session(self):
        account = self.authenticate()
        if account is None:
            return
        while True:
            print("\n1) Withdraw\n2) Deposit\n3) Transfer (same bank)\n4) Balance\n5) Exit")
            try:
                choice = int(input("Choose: "))
            except Exception:
                choice = 0
            if choice == 1:
                self.withdraw(account)
            elif choice == 2:
                self.deposit(account)
            elif choice == 3:
                self.transfer_out(account)
            elif choice == 4:
                self.balance(account)
            elif choice == 5:
                print("Goodbye.")
                break
            else:
                print("Invalid option.")

    def print_mini(self, account, limit=10):
        tx = account.get_transactions()[-limit:]
        if not tx:
            print("TX NONE")
            return
        for t in reversed(tx):
            meta_str = ""
            if "meta" in t:
                meta = t["meta"]
                if isinstance(meta, dict):
                    if "mix" in meta:
                        parts = []
                        for d in sorted(meta["mix"].keys(), reverse=True):
                            n = meta["mix"][d]
                            if n > 0:
                                parts.append(f"{d}x{n}")
                        meta_str = " ".join(parts)
                    elif "to" in meta:
                        meta_str = f"to:{meta['to']}"
                    elif "from" in meta:
                        meta_str = f"from:{meta['from']}"
                else:
                    meta_str = str(meta)
            line = f"TX {t['id']} {t['type']} {t['amount']} BAL {t['balance_after']}"
            if meta_str:
                line += f" {meta_str}"
            print(line)

    def run_state_machine(self):
        # Command-driven loop as per spec
        self.state = "IDLE"
        self.current_account = None
        self.pin_tries = self.PIN_TRIES
        while True:
            try:
                line = input().strip()
            except EOFError:
                break
            if not line:
                continue
            # Enforce single-space tokenization and uppercase commands
            if "\t" in line or "  " in line:
                print("ERROR FORMAT")
                continue
            parts = line.split()
            raw_cmd = parts[0]
            if raw_cmd != raw_cmd.upper():
                print("ERROR FORMAT")
                continue
            cmd = raw_cmd
            args = parts[1:]

            if self.state == "IDLE":
                if cmd == "CARD" and len(args) == 1:
                    ac = args[0]
                    acc = self.bank.find(ac)
                    if acc is None:
                        print("ERROR UNKNOWN_ACCOUNT")
                        continue
                    self.current_account = acc
                    self.state = "CARD_INSERTED"
                    self.pin_tries = self.PIN_TRIES
                    print(f"CARD_OK {ac}")
                elif cmd == "QUIT":
                    break
                else:
                    print("ERROR INVALID_STATE")

            elif self.state == "CARD_INSERTED":
                if cmd == "PIN" and len(args) == 1 and args[0].isdigit() and len(args[0]) == 4:
                    pin = int(args[0])
                    if self.current_account.verify_pin(pin):
                        self.state = "AUTHENTICATED"
                        print("PIN_OK")
                    else:
                        self.pin_tries -= 1
                        print(f"PIN_INVALID {self.pin_tries}")
                        if self.pin_tries == 0:
                            print("CARD_EJECTED")
                            self.state = "IDLE"
                            self.current_account = None
                else:
                    print("ERROR FORMAT")

            elif self.state == "AUTHENTICATED":
                if cmd == "BALANCE" and len(args) == 0:
                    if self.current_account.transfer("BALANCE"):
                        print(f"BALANCE {self.current_account.get_balance()}")
                elif cmd == "WITHDRAW":
                    if len(args) == 1 and args[0].isdigit():
                        amt = int(args[0])
                        self._withdraw_amount(self.current_account, amt)
                    else:
                        print("ERROR FORMAT")
                elif cmd == "DEPOSIT" and len(args) == 1 and args[0].isdigit():
                    amt = int(args[0])
                    self._deposit_amount(self.current_account, amt)
                elif cmd == "TRANSFER" and len(args) == 2 and args[1].isdigit():
                    tgt = args[0]
                    amt = int(args[1])
                    self._transfer_amount(self.current_account, tgt, amt)
                elif cmd in ("DEPOSIT", "TRANSFER"):
                    print("ERROR FORMAT")
                elif cmd == "MINI" and len(args) == 0:
                    self.print_mini(self.current_account, limit=5)
                elif cmd == "EJECT" and len(args) == 0:
                    print("CARD_EJECTED")
                    self.state = "IDLE"
                    self.current_account = None
                else:
                    print("ERROR INVALID_STATE")


if __name__ == "__main__":
    bank = Bank()
    atm_device = ATMDevice(bank)

    # Option A — interactive menu-based session (prompts shown)
    print("Starting ATM interactive session. Use the prompts.")
    atm_device.session()

    # Option B — command-driven session (uncomment to use instead).
    print("Starting ATM command-driven session. Enter commands like: CARD 1001")
    atm_device.run_state_machine()
