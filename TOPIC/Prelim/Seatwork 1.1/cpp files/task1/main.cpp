#include <iostream>

int main() {
    
    const int cap = 3;
    float quiz_items[cap] = {};
    float quiz_scores[cap] = {}; 
    float total_score = 0, score_average = 0, score_average_p = 0;
    int i;

    for (i = 0; i < cap; i++) {
        std::cout << "Enter total items of Quiz " << i+1 << ": ";
        std::cin >> quiz_items[i];

        std::cout << "Quiz " << i+1 << " score: ";
        std::cin >> quiz_scores[i];

        if(quiz_scores[i] > quiz_items[i]) {
            std::cout << "invalid score";
            return 0;
        }

        std::cout << "Score: " << quiz_scores[i] << " / " << quiz_items[i] << std::endl;  
        total_score += quiz_scores[i];
        score_average_p += ((quiz_scores[i]/quiz_items[i]) / cap) *100;

    }

    std::cout << std::endl;

    score_average = total_score / 3;

    std::cout << "Total scores: " << total_score << std::endl;
    std::cout << "Average score: " << score_average << std::endl;
    std::cout << "Average score %: " << score_average_p << "%" << std::endl;
    

    return 0;
}

