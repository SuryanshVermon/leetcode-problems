class H2O 
{

private:
    mutex mtx;
    condition_variable cv;
    size_t count;   

public:
    H2O():count(0)
    {
        
    }

    void hydrogen(function<void()> releaseHydrogen) 
    {
        
        unique_lock<mutex> lock(mtx);

        cv.wait(lock,[this](){return count != 2 ;} );
        count++;
        releaseHydrogen();
        cv.notify_all();
        }

    void oxygen(function<void()> releaseOxygen) 
    {
        std::unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this](){return count == 2;});
        releaseOxygen();
        count = 0;
        cv.notify_all();
    }
};