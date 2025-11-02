#include <iostream>
#include<vector>
#include <unordered_map>

using namespace std;

int totalFruit(vector<int> & arr){
    int maxlength = 0;

    for(int start = 0; start < arr.size(); start++){
        unordered_map<int, int> basket;
        int currCount = 0;

        for(int end = start; end < arr.size(); end++){
            basket[arr[end]]++;

            if(basket.size() > 2){
                break;
            }

            currCount++;
        }
        maxlength = max(maxlength, currCount);

    }

    return maxlength;
}

int totalFruitBetter(vector<int> &arr){
    unordered_map<int, int> basket;
    int maxlen = 0;
    int left = 0;

    for(int right = 0; right < arr.size(); right++){
        basket[arr[right]]++;

        while(basket.size() > 2){
            basket[arr[left]]--;

            if(basket[arr[left]] == 0){
                basket.erase(arr[left]);
            }

            left++;

        }
        maxlen = max(maxlen, right - left +1);
    }

    return maxlen;
}

int totalFruitsOptimal(vector<int> &arr){
    int maxlen = 0;
    int lastFruit = -1, secondLastFruit = -1;
    int currCount = 0, lastFruitStreak = 0;

    for(int fruit: arr){
        if(fruit == lastFruit || fruit == secondLastFruit){
            currCount++;
        } else {
            currCount = lastFruitStreak+1;
        }

        if(fruit == lastFruit){
            lastFruitStreak++;
        } else {
            lastFruitStreak = 1;
            secondLastFruit = lastFruit;
            lastFruit = fruit;
        }

        maxlen = max(maxlen, currCount);
    }

    return maxlen;
}
int main(){
    vector<int> arr = {1, 2, 2, 3, 2};

    int result = totalFruitsOptimal(arr);
    cout << "Result: " << result << endl;
    
}