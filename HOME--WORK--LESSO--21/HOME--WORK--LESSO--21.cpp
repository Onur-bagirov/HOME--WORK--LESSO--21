#include <iostream>

using namespace std;

// Function and Template Function
//==========================================================

template <typename T>
void RandomArrayOne(T array[], int size, T min, T max) 
{
    srand(time(NULL));

    for (int i = 0; i < size; i++) 
    {
        array[i] = rand() % (max - min + 1) + min;
    }
}

template <typename T>
void ShowArrayOne(T array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << array[i] << ",";
    }
    cout << endl;
}

//==========================================================

template <typename T>
void BubbleArrayThree(T array[], int size, bool ascending) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (ascending) {
                if (array[j] > array[j + 1]) 
                {
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
            else {
                if (array[j] < array[j + 1]) 
                {
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}

template <typename T>
void SelectionArrayThree(T array[], int size, bool ascending) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        int index = i;

        for (int j = i + 1; j < size; j++) 
        {
            if (ascending && array[j] < array[index] || (!ascending && array[j] > array[index])) 
            {
                index = j;
            }
        }

        T temp = array[index];
        array[index] = array[i];
        array[i] = temp;
    }
}

template <typename T>
void InsertionArrayThree(T array[], int size, bool ascending) 
{
    for (int i = 1; i < size; i++) 
    {
        T key = array[i];
        int j = i - 1;

        while (j >= 0 && (ascending && array[j] > key) || (!ascending && array[j] < key)) 
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

//==========================================================

template <typename T>
int searchArrayNum(T array[], int size, T find_num, T min, T max) 
{
    srand(time(NULL));

    for (int i = 0; i < size; i++) 
    {
        array[i] = rand() % (max - min + 1) + min;

        if (array[i] == find_num) 
        {
            return i;
        }
    }
    return -1;
}

//==========================================================

template <typename T>
T RandomNumber() {
    return rand() % 6 + 1;
}

template <typename T>
void PlayGame(T Choice) 
{
    T User_play[5] = {};
    T Robot_play[5] = {};
    int user_score = 0;
    int robot_score = 0;

    for (int i = 0; i < 5; i++) 
    {
        if (Choice == 0) 
        {
            cout << "\n\n\n";
            system("pause");
            cout << "\n\n\n";
            cout << "====================================";
            User_play[i] = RandomNumber<T>();
            user_score += User_play[i];
            cout << "User's roll: " << User_play[i] << endl;

            Robot_play[i] = RandomNumber<T>();
            robot_score += Robot_play[i];
            cout << "Robot's roll: " << Robot_play[i] << endl;
        }
        else if (Choice == 1) {
            Robot_play[i] = RandomNumber<T>();
            robot_score += Robot_play[i];
            cout << "Robot's roll: " << Robot_play[i] << endl;

            User_play[i] = RandomNumber<T>();
            user_score += User_play[i];
            cout << "User's roll: " << User_play[i] << endl;
        }

        Choice = 1 - Choice;
    }
    cout << "=======================================\n";
    cout << "\tResult\n";

    cout << "User Score: " << user_score << endl;
    cout << "Robot Score: " << robot_score << endl;

    if (user_score > robot_score) 
    {
        cout << "User is the winner with score: " << user_score << endl;
    }
    else if (user_score < robot_score) 
    {
        cout << "Robot is the winner with score: " << robot_score << endl;
    }
    else 
    {
        cout << "The game is a draw with score: " << user_score << endl;
    }
}

//==========================================================

int main() {
    srand(time(0));

    cout << "====================================";
    cout << "\n\nTap - 1\n\n";

    int min_num, max_num;
    int arrayOneSize[10] = {};

    cout << "Enter min number: ";
    cin >> min_num;

    cout << "Enter max number: ";
    cin >> max_num;

    cout << "Array: ";
    RandomArrayOne(arrayOneSize, 10, min_num, max_num);
    ShowArrayOne(arrayOneSize, 10);

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "====================================";
    cout << "\n\nTap - 2\n\n";

    cout << "Array: ";
    ShowArrayOne(arrayOneSize, 10);

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "====================================";
    cout << "\n\nTap - 3\n\n";

    int arrayThreeSize[10] = {};
    int choiceThree;

    cout << "1 - Descending;\n0 - Ascending\n";
    cout << "\nEnter choice: ";
    cin >> choiceThree;

    cout << "\n\nBubble Sort: ";
    RandomArrayOne(arrayThreeSize, 10, min_num, max_num);
    BubbleArrayThree(arrayThreeSize, 10, choiceThree);
    ShowArrayOne(arrayThreeSize, 10);

    cout << "\n\nSelection Sort: ";
    RandomArrayOne(arrayThreeSize, 10, min_num, max_num);
    SelectionArrayThree(arrayThreeSize, 10, choiceThree);
    ShowArrayOne(arrayThreeSize, 10);

    cout << "\n\nInsertion Sort: ";
    RandomArrayOne(arrayThreeSize, 10, min_num, max_num);
    InsertionArrayThree(arrayThreeSize, 10, choiceThree);
    ShowArrayOne(arrayThreeSize, 10);

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "====================================";
    cout << "\n\nTap - 4\n\n";

    int min_num_four, max_num_four, findNumberArray;
    int arrayFourSize[10] = {};

    cout << "Enter min number: ";
    cin >> min_num_four;

    cout << "Enter max number: ";
    cin >> max_num_four;

    cout << "Enter number to find: ";
    cin >> findNumberArray;

    int array_index = searchArrayNum(arrayFourSize, 10, findNumberArray, min_num_four, max_num_four);

    if (array_index != -1) 
    {
        cout << "Number's Index: " << array_index << endl;
    }
    else 
    {
        cout << "Number not found" << endl;
    }

    cout << "Array: ";
    ShowArrayOne(arrayFourSize, 10);

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "====================================";
    cout << "\n\nTap - 5\n\n";

    int choiceFive;

    cout << "0 - User starts, 1 - Robot starts / Enter choice: ";
    cin >> choiceFive;

    PlayGame(choiceFive);

    return 0;

    cout << "\n\n\n";
    system("pause");
    cout << "\n\n\n";
    cout << "====================================";
}
