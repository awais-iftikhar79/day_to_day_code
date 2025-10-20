#include <iostream>
#include <climits>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *A;

public:
    Stack(int s = 5)
    {
        size = s;
        top = -1;
        A = new int[size];
    }

    bool is_empty();
    bool is_full();
    void push(int value);
    int pop();
    int peek();
};
bool Stack::is_empty()
{
    return top == -1;
}

bool Stack::is_full()
{
    return (top == size - 1);
}

void Stack::push(int value)
{
    if (is_full())
    {
        cout << "Stack is already Full !" << endl;
        return;
    }
    A[++top] = value;
}

int Stack::pop()
{
    int x = -1;
    if (is_empty())
    {
        cout << "Stack is already empty !" << endl;
        return x;
    }
    x = A[top--];
    return x;
}

int Stack::peek()
{
    if (is_empty())
    {
        return -1;
    }
    return A[top];
}

int find_track(Stack holding_tracks[], int k, int car)
{
    int track = -1;
    int mintop = INT_MAX;

    for (int i = 0; i < k; i++)
    {
        if (holding_tracks[i].is_empty())
        {
            track = i;
            continue;
        }

        if (holding_tracks[i].peek() > car && holding_tracks[i].peek() < mintop)
        {
            mintop = holding_tracks[i].peek();
            track = i;
        }
    }
    return track;
}

int main()
{
    int n, k;
    cout << "Enter number of railroad cars: ";
    cin >> n;
    cout << "Enter number of holding tracks: ";
    cin >> k;

    int cars[n];
    cout << "Enter sequence of car numbers on the input track:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> cars[i];
    }

    Stack *holding_tracks = new Stack[k];
    for (int i = 0; i < k; i++)
    {
        holding_tracks[i] = Stack(n);
    }

    int *output = new int[n];  
    int output_index = 0;      
    int expected = 1;          

    cout << "\n--- Rearrangement Process ---\n";

    for (int i = 0; i < n; i++)
    {
        int car = cars[i];

        if (car == expected)
        {
            cout << "Move car " << car << " directly to Output Track.\n";
            output[output_index++] = car;
            expected++;

            
            bool moved;
            do
            {
                moved = false;
                for (int j = 0; j < k; j++)
                {
                    if (!holding_tracks[j].is_empty() && holding_tracks[j].peek() == expected)
                    {
                        int moved_car = holding_tracks[j].pop();
                        cout << "Move car " << moved_car << " from Holding Track H" << j + 1 << " to Output Track.\n";
                        output[output_index++] = moved_car;
                        expected++;
                        moved = true;
                    }
                }
            } while (moved);
        }
        else
        {
            int track = find_track(holding_tracks, k, car);
            if (track == -1)
            {
                cout << "No suitable holding track for car " << car << ". Rearrangement failed!\n";
                return 0;
            }
            holding_tracks[track].push(car);
            cout << "Move car " << car << " to Holding Track H" << track + 1 << ".\n";
        }
    }

    cout << "\n--- Final Output Sequence ---\n";
    for (int i = 0; i < output_index; i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;

    if (expected == n + 1)
        cout << "Successfully rearranged all cars!" << endl;
    else
        cout << "Rearrangement incomplete!" << endl;

    return 0;
}
