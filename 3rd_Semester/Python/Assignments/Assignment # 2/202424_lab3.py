reg="2024124"

# maximum number of hashtag blocks
m=int(reg[-1])+1    

# required underscores between consecutive hashtag blocks
reg_sum=0

for char in reg:
    if char.isdigit():
        reg_sum+=int(char)

n=(reg_sum%3)+1    

# maximum allowed length of any consecutive run of !
k=(int(reg[-2])%4)+2    

print(m, n, k)

def check_timeline(timelines):
    for timeline in timelines: 
        valid=True

        # Constraint 1     
        for char in timeline:
            if char!='#' and char!='_' and char!='!':
                print("REJECT")
                valid=False
                break

        if not valid:
            continue     
    
        # Constraint 2
        hash_count=0

        for char in timeline:
            if char=='#':
                hash_count+=1

        if hash_count>m:
            print("REJECT")
            continue

        # Constraint 3
        blocks=[]

        i=0

        while i<len(timeline):
            if timeline[i]=='#':
                start=i

                while i+1<len(timeline) and timeline[i+1]=='#':
                    i+=1

                end=i
                blocks.append((start, end))

            i+=1

        for i in range(len(blocks)-1):
            end_current=blocks[i][1]
            start_next=blocks[i+1][0]
            region=timeline[end_current+1:start_next]

            underscore_count=0
            max_underscore_streak=0

            for char in region:
                if char=='_':
                    underscore_count+=1
                    max_underscore_streak=max(max_underscore_streak, underscore_count)
                
                elif char=='!':
                    underscore_count=0

            if max_underscore_streak<n:
                print("REJECT")
                valid=False
                break

        if not valid:
            continue

        # Constraint 4
        i=0

        while i<len(timeline):
            excl_counter=0

            if timeline[i]=='!':
                excl_counter+=1

                while i+1<len(timeline) and timeline[i+1]=='!':
                    i+=1
                    excl_counter+=1

                if excl_counter>k:
                    print("REJECT")
                    valid=False
                    break

            i+=1
        
        if not valid:
            continue

        print("ACCEPT")

def main():
    timelines=['##___##', '##_##', '#!!!!!#', '####']

    check_timeline(timelines)

main()