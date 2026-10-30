#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>

int globalValue = 0;
std::mutex mtx;
std::condition_variable cv;


int activeStep = 0;

void add(int value, int myStep) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [myStep] { return activeStep == myStep; });
    
    globalValue += value;

    activeStep = 0; 
    cv.notify_all();
}

void display(const std::string& label) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << label << ": globalValue = " << globalValue << std::endl;
}

void triggerStep(int step) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        activeStep = step;
    }
    cv.notify_all(); 
}

int main() {
    std::thread T1(add, 10, 1);
    std::thread T2(add, 20, 2);
    std::thread T3(add, 30, 3);

    display("Display 1 "); 

    triggerStep(1);
    T1.join();
    display("Display 2 ");

    triggerStep(2);
    T2.join();
    display("Display 3 "); 

    triggerStep(3);
    T3.join();
    display("Display 4 ");

    return 0;
}