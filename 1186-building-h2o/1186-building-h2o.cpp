class H2O {
    int d;
    std::mutex mtx;
    std::condition_variable cv;
    
public:
    H2O(): d(0) {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<std::mutex> lck(mtx);
        while (d >= 2) {
            cv.wait(lck);
        }
        releaseHydrogen();
        d++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<std::mutex> lck(mtx);
        while (d < 0) {
            cv.wait(lck);
        }
        releaseOxygen();
        d-=2;
        cv.notify_all();
    }
};