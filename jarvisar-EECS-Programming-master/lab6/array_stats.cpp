#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int randnumber(int upper){
    int random = (rand() % (upper+1));
    return random;
}

int summ(int arr[], int upper){
    int sum = 0;
    for (int i = 0; i < upper + 1; ++i){
        sum = sum + arr[i];
    }
    return sum;
}

int max(int arr[], int upper){
    int max = 0;
    for (int i = 0; i < upper + 1; ++i){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int min(int arr[], int upper){
    int min = 9999;
    for (int i = 0; i < upper + 1; ++i){
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

double mean(int arr[], int upper){
    double sum = summ(arr, upper);
    return (sum / (upper + 1.0));
}



int main()
{
    srand (time(NULL));
    int samples;
    cout << "Enter end range: " << endl;
    int upper;
    cin >> upper;
    while ((upper > 100) || (upper < 0)){
        cout << "Upper limit cannot be more than 100 (or negative)." << endl;
        cin >> upper;
    }
    cout << "Enter number of Samples: " << endl;
    cin >> samples;
    while ((samples < 10000) || (samples < 0)){
        cout << "Number of samples cannot be less than 10,000 (or negative)." << endl;
        cin >> samples;
    }
    int arr[upper+1];
    int i = 0;
    int temp;
    for (i = 0; i < upper+1; ++i){
        arr[i] = 0;
    }
    for (i = 0; i < samples; ++i){
        temp = randnumber(upper);
        arr[temp] = arr[temp] + 1;
    }
    int j = 0;
    int k = 0;
    int total = 0;
    int scale = max(arr,upper)/55;
    cout << "Index\tValue Bar" << endl;
    for (j = 0; j < upper+1; ++j){
        cout << j << "\t" << arr[j] << " ";
        for (k= 0; k < (arr[j]/scale); ++k){
            cout << "*";
        }
        cout << endl;
    }
    cout << "Scale: " << scale << " per *" << endl;
    cout << "Sample count: " << samples << endl;
    cout << "Min: " << min(arr,upper) << endl;
    cout << "Max: " << max(arr,upper) << endl;
    cout << "Sum: " << summ(arr,upper) << endl;
    cout << "Mean: " << mean(arr,upper) << endl;
    return 0;
}
