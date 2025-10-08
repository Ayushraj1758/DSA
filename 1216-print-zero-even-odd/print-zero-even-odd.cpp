class ZeroEvenOdd {
private:
    int n;
    int current;
    mutex mtx;
    condition_variable cv;
    bool zeroTurn;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        current = 1;
        zeroTurn = true; // start with zero
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return zeroTurn; }); // wait for zero's turn
            printNumber(0);
            zeroTurn = false; // next turn: odd or even
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return !zeroTurn && current % 2 == 0; });
            printNumber(current++);
            zeroTurn = true; // back to zero
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return !zeroTurn && current % 2 == 1; });
            printNumber(current++);
            zeroTurn = true; // back to zero
            cv.notify_all();
        }
    }
};
