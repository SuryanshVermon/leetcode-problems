
class ZeroEvenOdd {
private:
    int n;
    sem_t sem_z;
    sem_t sem_o;
    sem_t sem_e;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&sem_z, 0, 1);
        sem_init(&sem_o, 0, 0);
        sem_init(&sem_e, 0, 0);
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            sem_wait(&sem_z);
            printNumber(0);
            if (i % 2 == 0)
                sem_post(&sem_e);
            else
                sem_post(&sem_o);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&sem_e);
            printNumber(i);
            sem_post(&sem_z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&sem_o);
            printNumber(i);
            sem_post(&sem_z);
        }
    }

    ~ZeroEvenOdd() {
        sem_destroy(&sem_z);
        sem_destroy(&sem_o);
        sem_destroy(&sem_e);
    }
};