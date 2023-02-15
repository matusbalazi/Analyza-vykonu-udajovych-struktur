
#include "structures/heap_monitor.h"
#include "Tests.h"

//#include "structures/set/base_set.h"
//#include "structures/set/bit_set.h"

int main()
{
    initHeapMonitor();

    srand(time(0));

    //BaseSet* baza = new BaseSet();
    //structures::BitSet* bitovaMnozina = new structures::BitSet(baza);
    //structures::BitSet* bitovaMnozina2 = new structures::BitSet(baza);

    //bitovaMnozina->insert(1);
    //bitovaMnozina->insert(2);
    //bitovaMnozina->insert(3);
    //bitovaMnozina->insert(5);
    //bitovaMnozina->insert(6);
    ////
    //bitovaMnozina2->insert(1);
    ////bitovaMnozina2->insert(9);
    ////bitovaMnozina2->insert(8);
    //bitovaMnozina2->insert(5);
    ////bitovaMnozina2->insert(6);

    //cout << bitovaMnozina->isSubset(*bitovaMnozina2);
    //bitovaMnozina->print();
    //cout << endl;
    //bitovaMnozina2->print();
    //cout << endl;
    //structures::BitSet* bitovaMnozina3 = &bitovaMnozina->unionWith(*bitovaMnozina2);
    //cout << endl;
    //bitovaMnozina3->print();
    //cout << endl;
    //bitovaMnozina3 = &bitovaMnozina->intersection(*bitovaMnozina2);
    //cout << endl;
    //bitovaMnozina3->print();
    //cout << endl;
    //bitovaMnozina3 = &bitovaMnozina->substraction(*bitovaMnozina2);
    //cout << endl;
    //bitovaMnozina3->print();
 
    /*for (int i = 1; i <= bitovaMnozina->size(); i++) {
        cout << bitovaMnozina->contains(i);
        if (i % 64 == 0) {
            cout << endl;
        }
    }
    cout << endl;*/

   /* cout << endl;
    cout << bitovaMnozina->contains(-2);
    cout << bitovaMnozina->contains(-1);
    cout << bitovaMnozina->contains(0);
    cout << bitovaMnozina->contains(1);
    cout << endl;
    cout << bitovaMnozina->contains(62);
    cout << bitovaMnozina->contains(63);
    cout << bitovaMnozina->contains(64);
    cout << bitovaMnozina->contains(65);
    cout << endl;
    cout << bitovaMnozina->contains(126);
    cout << bitovaMnozina->contains(127);
    cout << bitovaMnozina->contains(128);
    cout << bitovaMnozina->contains(129);
    cout << endl;
    cout << bitovaMnozina->contains(190);
    cout << bitovaMnozina->contains(191);
    cout << bitovaMnozina->contains(192);
    cout << bitovaMnozina->contains(193);
    cout << endl;
    cout << bitovaMnozina->contains(254);
    cout << bitovaMnozina->contains(255);
    cout << bitovaMnozina->contains(256);
    cout << bitovaMnozina->contains(257);
    cout << endl;*/

    Tests* test = new Tests();

    test->run();

    delete test;
    test = nullptr;

    return 0;
}

