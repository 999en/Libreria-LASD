
// #include "..."

/* ************************************************************************** */

#include <iostream>
#include <random>

#define DimensioneContainer 10

using namespace std;

default_random_engine gen(random_device{}());
uniform_int_distribution<int> RandomNumber(0, 100);

#include "test.hpp"
/* ************************************************************************** */

void myTest() {
  int scelta;
  cout<<"\n\n\nQuale test vuoi eseguire? \n";
  cout<<"Esercizio1 : (premi 1) \n";
  cout<<"Esercizio2 : (premi 2) \n";
  cin>>scelta;

  if(scelta == 1) TestEsercizio1();
  else if(scelta == 2) TestEsercizio2();
}

bool TestCostruttori()
{
    bool TestCostruttoriErrori = true;

    cout<<"\n\n***************TEST DEI COSTRUTTORI: \n";
    
    cout<<"\nTestCostruttore Vec->QueueVec(Copy): ";
    lasd::Vector<int> vc1(DimensioneContainer);
    for(uint i = 0; i < DimensioneContainer; i++) {
      vc1[i] = i;
    }
    lasd::QueueVec<int> qv1(vc1);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc1[i] != qv1.HeadNDequeue()) {
          cout<<"ERRORE!";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore Vec->QueueVec(Move): ";
    lasd::QueueVec<int> qv2(move(vc1));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc1[i] != qv2.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore QueueVec->QueueVec(copy): ";
    lasd::QueueVec<int> qv3;
    for(uint i = 0; i < DimensioneContainer; i ++) {
      qv3.Enqueue(i);
    }
    lasd::QueueVec<int> qv4(qv3);
    if(qv4 == qv3) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }
  
    cout<<"\nTestCostruttore QueueVec->QueueVec(move): ";
    lasd::QueueVec<int> qv5(move(qv4));
    if(qv4.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }


    cout<<"\nTestCostruttore List->QueueVec(Copy): ";
    lasd::List<int> lst1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      lst1.Insert(i);
    }
    lasd::QueueVec<int> qv6(lst1);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst1[i] != qv6.HeadNDequeue()) {
          cout<<"ERRORE!";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore List->QueueVec(Move): ";
    lasd::QueueVec<int> qv7(move(lst1));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst1[i] != qv7.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore Vec->StackVec(Copy): ";
    lasd::Vector<int> vc2(DimensioneContainer);
    for(uint i = 0; i < DimensioneContainer; i++) {
      vc2[i] = i;
    }
    lasd::StackVec<int> stk1(vc2);
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(vc2[i] != stk1.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == 0) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore Vec->StackVec(Move): ";
    lasd::StackVec<int> stk2(move(vc2));
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(vc2[i] != stk2.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    

    cout<<"\nTestCostruttore StackVec->StackVec(copy): ";
    lasd::StackVec<int> stk3;
    for(uint i = 0; i < DimensioneContainer; i ++) {
      stk3.Push(i);
    }
    lasd::StackVec<int> stk4(stk3);
    if(stk4 == stk3) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }
    
    cout<<"\nTestCostruttore StackVec->StackVec(move): ";
    lasd::StackVec<int> stk5(move(stk4));
    if(stk4.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    
    cout<<"\nTestCostruttore List->StackVec(Copy): ";
    lasd::List<int> lst2;
    for(uint i = 0; i < DimensioneContainer; i++) {
      lst2.Insert(i);
    }
    lasd::StackVec<int> stk6(lst2);
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(lst2[i] != stk6.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore List->StackVec(Move): ";
    lasd::StackVec<int> stk7(move(lst2));
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(lst2[i] != stk7.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore List->QueueLst(copy): ";
    lasd::QueueLst<int> qlst1(lst2);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != qlst1.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore List->QueueLst(move): ";
    lasd::Vector<int> tmpVec(lst2);
    lasd::QueueLst<int> qlst2(move(tmpVec));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != qlst2.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore QueueLst->QueueLst(copy): ";
    lasd::QueueLst<int> qlst3;
    for(int i = 0; i < DimensioneContainer; i++) {
      qlst3.Enqueue(i);
    }
    lasd::QueueLst<int> qlst4(qlst3);
    if(qlst3 == qlst4) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore QueueLst->QueueLst(move): ";
    lasd::QueueLst<int> qlst5(move(qlst4));
    if(qlst4.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore Vec->QueueLst(copy): ";
    lasd::QueueLst<int> qlst6(vc2);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != qlst6.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
        TestCostruttoriErrori |= false;
      }
    }

    cout<<"\nTestCostruttore Vec->QueueLst(move): ";
    lasd::Vector<int> tmpVec2(vc2);
    lasd::QueueLst<int> qlst7(move(tmpVec2));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != qlst7.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
        TestCostruttoriErrori |= false;
      }
    }

    cout<<"\nTestCostruttore List->StackLst(copy): ";
    lasd::StackLst<int> stclst1(lst2);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != stclst1.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore List->StackLst(move): ";
    lasd::List<int> tmpLst(lst2);
    lasd::StackLst<int> stclst2(move(tmpLst));  
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != stclst2.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore StackLst->StackLst(copy): ";
    lasd::StackLst<int> stclst3(stclst2);    
    if(stclst2 == stclst3) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore StackLst->StackLst(move): ";
    lasd::Vector<int> tmpVec3(vc2);
    lasd::StackLst<int> stclst4(move(tmpVec3));    
    if(stclst3.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore Vec->StackLst(copy): ";
    lasd::StackLst<int> stclst5(vc2);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != stclst5.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore Vec->StackLst(move): ";
    lasd::Vector<int> tmpVec4(vc2);
    lasd::StackLst<int> stclst6(move(tmpVec4));    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != stclst6.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore Vec->List(copy): ";
    lasd::List<int> list1(vc2);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != list1[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore Vec->List(move): ";
    lasd::Vector<int> tmpVec5(vc2);
    lasd::List<int> list2(move(tmpVec5));    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != list2[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore List->Vec(copy): ";
    lasd::Vector<int> vector1(list1);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vector1[i] != list1[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore List->Vec(move): ";
    lasd::Vector<int> vector2(move(list1));    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vector2[i] != list1[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    return TestCostruttoriErrori;
}

bool TestAssegnazioni()
{
    bool TestAssergnazioniErrori = true;

    cout<<"\n\n***************TEST DELLE ASSEGNAZIONI: \n";

    cout<<"\nTestAssegnazione QueueVec->QueueVec(copy): ";
    lasd::QueueVec<int> qvc1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      qvc1.Enqueue(i);
    }
    lasd::QueueVec<int> qvc2;
    qvc2 = qvc1;
    if(qvc1 == qvc2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione QueueVec->QueueVec(move): ";
    lasd::QueueVec<int> qvc3;
    qvc3 = move(qvc2);
    if(qvc3 == qvc1 && qvc2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione StackVec->StackVec(copy): ";
    lasd::StackVec<int> stck1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      stck1.Push(i);
    }
    lasd::StackVec<int> stck2;
    stck2 = stck1;
    if(stck1 == stck2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione StackVec->StackVec(move): ";
    lasd::StackVec<int> stck3;
    stck3 = move(stck2);
    if(stck3 == stck1 && stck2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione QueueLst->QueueLst(copy): ";
    lasd::QueueLst<int> qlst1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      qlst1.Enqueue(i);
    }
    lasd::QueueLst<int> qlst2;
    qlst2 = qlst1;
    if(qlst1 == qlst2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione QueueVec->QueueVec(move): ";
    lasd::QueueLst<int> qlst3;
    qlst3 = move(qlst2);
    if(qlst3 == qlst1 && qlst2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }


    cout<<"\nTestAssegnazione StackLst->StackLst(copy): ";
    lasd::StackLst<int> stcklst1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      stcklst1.Push(i);
    }
    lasd::StackLst<int> stcklst2;
    stcklst2 = stcklst1;
    if(stcklst1 == stcklst2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione StackLst->StackLst(move): ";
    lasd::StackLst<int> stcklst3;
    stcklst3 = move(stcklst2);
    if(stcklst3 == stcklst1 && stcklst2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    return TestAssergnazioniErrori;
}



bool TestDictionaryFunctions()
{ 
  bool TestDictionaryErrori = true;

  cout<<"\n\n***************TEST DELLE FUNZIONI DEI DICTIONARY: \n";

  lasd::Vector<int> v1(3);
  v1[0]=1; v1[1]=2; v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=6; v2[1]=7; v2[2]=8;

  lasd::List<int> l1;
  l1.InsertAtBack(3); l1.InsertAtBack(4); l1.InsertAtBack(5);

  cout<<"\nTestDictionary InsertAll(copy): ";
  bool test1 = l1.InsertAll(v1);
  bool test2 = l1.InsertAll(v2);
  if(test1 || !(test2)) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  cout<<"\nTestDictionary InsertAll(move): ";
  lasd::List<int> l2;
  l2.InsertAtBack(3); l2.InsertAtBack(4); l2.InsertAtBack(5);
  test1 = l2.InsertAll(move(v1));
  test2 = l2.InsertAll(move(v2));
  if(test1 || !(test2)) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  lasd::Vector<int> v3(3);
  v3[0]=1; v3[1]=2; v3[2]=3;

  lasd::Vector<int> v4(3);
  v4[0]=3; v4[1]=4; v4[2]=5;

  cout<<"\nTestDictionary InsertSome(copy): ";
  lasd::List<int> l3;
  l3.InsertAtBack(3); l3.InsertAtBack(4); l3.InsertAtBack(5);
  bool test3 = l3.InsertSome(v3);
  bool test4 = l3.InsertSome(v4);
  if(!(test3) || test4) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  cout<<"\nTestDictionary InsertSome(move): ";
  lasd::List<int> l4;
  l4.InsertAtBack(3); l4.InsertAtBack(4); l4.InsertAtBack(5);
  test3 = l4.InsertSome(move(v3));
  test4 = l4.InsertSome(move(v4));
  if(!(test3) || test4) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  lasd::Vector<int> v5(3);
  v5[0]=1; v5[1]=2; v5[2]=3;

  lasd::Vector<int> v6(3);
  v6[0]=4; v6[1]=5; v6[2]=6;

  cout<<"\nTestDictionary RemoveAll: ";
  lasd::List<int> l5;
  l5.InsertAtBack(3); l5.InsertAtBack(4); l5.InsertAtBack(5);
  l5.InsertAtBack(6); l5.InsertAtBack(7);
  bool test5 = l5.RemoveAll(v5);
  bool test6 = l5.RemoveAll(v6);
  if(test5 || !(test6)) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }


  cout<<"\nTestDictionary RemoveSome: ";
  lasd::Vector<int> v7(3);
  v7[0]=1; v7[1]=2; v7[2]=3;

  lasd::Vector<int> v8(3);
  v8[0]=6; v8[1]=7; v8[2]=8;

  lasd::List<int> l6;
  l6.InsertAtBack(3); l6.InsertAtBack(4); l6.InsertAtBack(5);
  bool test7=l6.RemoveSome(v7);
  bool test8=l6.RemoveSome(v8);
  if(!(test7) || test8) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  return TestDictionaryErrori;
}


 

bool TestSort()
{
  cout<<"\n\n***************TEST DI SORTING: \n";

  cout<<"\nTestSort SortingInt: ";
  bool TestSortInt = true;
  lasd::SortableVector<int> v1(DimensioneContainer);
  for(ulong i = 0; i < v1.Size(); i++){
    v1[i] = RandomNumber(gen);
  }
  v1.Sort();
  for(ulong i = 1; i < v1.Size(); i++){
    TestSortInt &= (v1[i-1] <= v1[i]);
  }
  if(TestSortInt) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
  }

  cout<<"\nTestSort SortingEmptyVector(borderline case): ";
  bool TestSortEmpty = true;
  lasd::SortableVector<int> v2(0);
  v2.Sort();
  for(ulong i = 1; i<v2.Size(); i++) {
    TestSortEmpty &= (v2[i-1]<=v2[i]);
  } 
  if(TestSortEmpty) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
  }
    

  return (TestSortInt && TestSortEmpty);
}

bool TestQueueVec()
{
  bool TestQueueVec = true;
  cout<<"\n***************TEST DI QUEUEVEC: \n";
  cout<<"\nTestSort QueueVec: \n";
  lasd::QueueVec<int> queue;

  queue.Enqueue(5);
  cout<<"Testa '"<<queue.Head()<<"': ";
  int value = queue.HeadNDequeue();
  if(value == 5) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(1);
  queue.Enqueue(3);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 1) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(2);
  queue.Enqueue(4);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 3) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(1);
  queue.Enqueue(7);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 2) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(2);
  queue.Enqueue(2);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 4) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(6);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 1) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(8);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 7) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(1);
  queue.Enqueue(4);

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 2) {
    cout<<"CORRETTO!\n";
  } else {

    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 2) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 6) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 8) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  return TestQueueVec;
}



bool TestIteratori() {
  bool testIteratori = true;
  int lines = 1;
  cout<<"\n\nBegin of (BST into) Iterator Test: "<<endl;

  lasd::BinaryTreeLnk<int> btlnk;
  lasd::BTInOrderIterator<int> inOrderBSTlnk(btlnk);
  if(inOrderBSTlnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<"Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BTInOrderIterator<int> inOrderBSTmovelnk(std::move(btlnk));
  if(inOrderBSTmovelnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<" Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }

  lasd::BinaryTreeVec<int> btvec;
  lasd::BTInOrderIterator<int> inOrderBSTvec(btvec);
  if(inOrderBSTvec.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<"Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BTInOrderIterator<int> inOrderBSTmovevec(std::move(btvec));
  if(inOrderBSTmovevec.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<" Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }

  lasd::List<int> lst;
  for(int i=0; i<6; i++) {
        lst.InsertAtBack(i);
  }

  lasd::BinaryTreeLnk<int> btLnk(lst);

  cout<<"MAP:"<<endl;
  cout<<"Expected: 0->1->3->4->2->5->"<<endl;
  cout<<"Map ottenuta: ";
  btLnk.Map(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;

  cout<<"PRE_ORDER_MAP:"<<endl;
  cout<<"Expected: 0->1->3->4->2->5->"<<endl;
  cout<<"PreOrderMap: ";
  btLnk.PreOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTPreOrderIterator<int> itrPre(btLnk);
  cout<<"\nPreOrderIterator: ";
  while(!(itrPre.Terminated())){
    cout<<*itrPre<<"->";
    ++itrPre;
  }
  cout<<endl;

  cout<<"POST_ORDER_MAP:"<<endl;
  cout<<"Expected: 3->4->1->5->2->0->"<<endl;
  cout<<"PostOrderMap: ";
  btLnk.PostOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTPostOrderIterator<int> itrPost(btLnk);
  cout<<"\nPostOrderIterator: ";
  while(!(itrPost.Terminated())){
    cout<<*itrPost<<"->";
    ++itrPost;
  }
  cout<<endl;

  cout<<"IN_ORDER_MAP:"<<endl;
  cout<<"Expected: 3->1->4->0->5->2->"<<endl;
  cout<<"InOrderMap: ";
  btLnk.InOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTInOrderIterator<int> itrIn(btLnk);
  cout<<"\nInOrderIterator: ";
  while(!(itrIn.Terminated())){
    cout<<*itrIn<<"->";
    ++itrIn;
  }
  cout<<endl;

  cout<<"BREADTH_ORDER_MAP:"<<endl;
  cout<<"Expected: 0->1->2->3->4->5->"<<endl;
  cout<<"BreadthMap: ";
  btLnk.BreadthMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTBreadthIterator<int> itrBreadth(btLnk);
  cout<<"\nBreadthOrderIterator: ";
  while(!(itrBreadth.Terminated())){
    cout<<*itrBreadth<<"->";
    ++itrBreadth;
  }
  cout<<endl;

  lasd::SortableVector<int> vec(RandomNumber(gen) + 1);
  for(lasd::ulong i = 0; i < vec.Size(); i++) {
    vec[i] = RandomNumber(gen);
  }
  vec.Sort();
  lasd::BinaryTreeVec<int> btvec1(vec);
  lasd::BTBreadthIterator<int> breadthIterVec(btvec1);
  int next = 0;
  while(!breadthIterVec.Terminated()){
    int previous = *breadthIterVec;
    if(!(++breadthIterVec).Terminated()){
      next = *breadthIterVec;
    }
    if(previous <= next) {
      testIteratori &= true;
    } else {
      testIteratori &= false;
      cout<<lines++<<" BTBredthIterator NON costruito correttamente da BTVec: Error!"<<endl;
      break;
    }
  }
  if(testIteratori == true) {
    cout<<lines++<<" BTBredthIterator costruito correttamente da BTVec: Correct!"<<endl;    
  }
  breadthIterVec.Reset();
  if(*breadthIterVec == vec[0]) {
    cout<<lines++<<" L'iteratore è stato resettato correttamente: Correct!"<<endl;
  } else {
    cout<<lines++<<" L'iteratore NON è stato resettato correttamente: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BinaryTreeLnk<int> btlnk1;
  lasd::BTInOrderIterator<int> postOrderBSTlnk(btlnk1);
  if(postOrderBSTlnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<"Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BTInOrderIterator<int> postOrderBSTmovelnk(std::move(btlnk));
  if(postOrderBSTlnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<" Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }

  return testIteratori;
}




bool TestBTVec()
{
  bool testBTVec = true;
  int lines = 1;
  cout<<"\n\nBegin of BTVec Test: "<<endl;
  lasd::List<int>lst;
  for(int i = 0; i < RandomNumber(gen) + 1; i++){
    lst.Insert(RandomNumber(gen));
  }
  lasd::BinaryTreeVec<int>btvec1(lst);
  lasd::BinaryTreeVec<int>btvec2(std::move(lst));
  if(btvec1 == btvec2) {
    cout<<lines++<<" Two BtVec are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtVec are NOT equals: Error!"<<endl;
    testBTVec &= false;
  }
  btvec2.Clear();
  btvec1 = btvec2;
  if(btvec1.Empty()) {
    cout<<lines++<<" BTVec1 is now Empty: Correct!"<<endl;
  } else {
    cout<<lines++<<" BTVec1 is NOT Empty: Error!"<<endl;
    testBTVec &= false;
  }
  if(btvec1 == btvec2) {
    cout<<lines++<<" Two BtVec are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtVec are NOT equals: Error!"<<endl;
    testBTVec &= false;
  }
  lasd::List<double> vec;
  lasd::BinaryTreeVec<double> btvec3;
  btvec3 = std::move(vec);
  try{
    btvec3.Root();
  } catch (const std::length_error& e) {
      // Gestione dell'eccezione
      std::cerr << lines++ << " Caught std::length_error: " << e.what() << " Correct! " <<std::endl;
  } catch (const std::exception& e) {
    std::cerr << lines++ << " Wrong exception called:" << e.what() << " Error!" <<std::endl;
    testBTVec &= false;
  }
  lasd::Vector<double> vec1(RandomNumber(gen) + 1);
  for(lasd::ulong i = 0; i < vec1.Size() - 1; i++){
    vec1[i] = RandomNumber(gen);
  }
  //creo una ripetizione
  vec1[0]++;
  vec1[vec1.Size() - 1] = vec1[0];
  lasd::BinaryTreeLnk<double> btlnk1(vec1);
  lasd::BinaryTreeVec<double> btvec4(btlnk1);
  double accumulator1 = 0;
  cout<<" Printing new BTLnk :";
  btlnk1.Map(
    [&accumulator1](double dat){
      cout<<dat<<"->";
      accumulator1 += dat;
    }
  );
  cout<<"\n BTLnk's all value sum is: "<<accumulator1<<endl;

  double accumulator2 = 0;
  cout<<" Printing new BTVec :";
  btvec4.Map(
    [&accumulator2](double dat){
      cout<<dat<<"->";
      accumulator2 += dat;
    }
  );
  cout<<"\n BTVec(BTLnk)'s all value sum is: "<<accumulator2<<endl;
  if(accumulator1 == accumulator2) {
    cout<<lines++<<" BTVec & BTLnk are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" BTVec & BTLnk are NOT equals: Error!"<<endl;
    testBTVec &= false;
  }

  lasd::BST<double> BST1(btvec4);
  double accumulator3 = 0;
  cout<<" Printing new BST :";
  BST1.Traverse(
    [&accumulator3](double dat){
      cout<<dat<<"->";
      accumulator3 += dat;
    }
  );
  cout<<"\n BST's all value sum is: "<<accumulator3<<endl;
  if(accumulator2 != accumulator3) {
    cout<<lines++<<" BST & (BTLnk & BTVec) are NOT equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" BST & (BTLnk & BTVec) are equals: Error!"<<endl;
    testBTVec &= false;
  }

  lasd::Vector<int> vec3(RandomNumber(gen) + 1);
  for(lasd::ulong i = 0; i < vec3.Size(); i++){
    vec3[i] = RandomNumber(gen);
  }
  lasd::Vector<int> vec4(vec3);
  lasd::BinaryTreeLnk<int> btlnk5(std::move(vec3));
  lasd::BinaryTreeVec<int> btvec5(std::move(vec4));
  if(btlnk5.lasd::BinaryTree<int>::operator==(btvec5)){
    cout<<lines++<<" btlnk and bvec(move assignament from the same vector) are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" btlnk and bvec(move assignament from the same vector) are NOT equals: Error!"<<endl;
  }
  lasd::BinaryTreeLnk<int> btlnk6(std::move(btlnk5));
  lasd::BinaryTreeVec<int> btvec6(std::move(btvec5));
  if(btlnk6.lasd::BinaryTree<int>::operator==(btvec6)){
    cout<<lines++<<" btlnk(from move(btvec)) and btvec are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" btlnk(from move(btvec)) and btvec are NOT equals: Error!"<<endl;
  }

  lasd::List<int>lista;
  lista.Insert(RandomNumber(gen));
  lista.Insert(RandomNumber(gen));

  lasd::BinaryTreeVec<int>btvec7(std::move(lista));
  lasd::List<int>list(btvec7);
  for(lasd::ulong i=0; i< list.Size();i++) {
    cout<<lines++<<" extracted value from List(BTLnk): "<<list[i]<<" Correct!"<<endl;
  }

  lasd::List<int> list1;
  for(int i = 0; i < (RandomNumber(gen)%10) + 5; i++) {
    list1.Insert(RandomNumber(gen));
  }
  cout<<lines++<<" MAP LISTA:";
  list1.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  lasd::BinaryTreeVec<int> bintvec(list1);
  cout<<"\n"<<lines++<<" MAP:";
  bintvec.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" PREORDERMAP:";
  bintvec.PreOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" POSTORDERMAP:";
  bintvec.PostOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" INORDERMAP:";
  bintvec.InOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" BREADTHORDERMAP:";
  bintvec.BreadthMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );


  return testBTVec;
}

bool TestBTLnk()
{
  bool testBTLnk= true;
  int lines = 1;
  cout<<"\n\nBegin of BTLnk Test: "<<endl;
  lasd::List<int>lst;
  for(int i = 0; i < RandomNumber(gen) + 1; i++){
    lst.Insert(RandomNumber(gen));
  }
  lasd::BinaryTreeLnk<int>btlnk1(lst);
  lasd::BinaryTreeLnk<int>btlnk2(std::move(lst));
  if(btlnk1 == btlnk2) {
    cout<<lines++<<" Two BtLnk are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtLnk are NOT equals: Error!"<<endl;
    testBTLnk &= false;
  }
  btlnk2.Clear();
  btlnk1 = btlnk2;
  if(btlnk1.Empty()) {
    cout<<lines++<<" BtLnk1 is now Empty: Correct!"<<endl;
  } else {
    cout<<lines++<<" BtLnk1 is NOT Empty: Error!"<<endl;
    testBTLnk &= false;
  }
  if(btlnk1 == btlnk2) {
    cout<<lines++<<" Two BtLnk are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtLnk are NOT equals: Error!"<<endl;
    testBTLnk &= false;
  }
  lasd::List<double> vec;
  lasd::BinaryTreeLnk<double> btlnk3;
  btlnk3 = vec;
  try{
    btlnk3.Root();
  } catch (const std::length_error& e) {
      // Gestione dell'eccezione
      std::cerr << lines++ << " Caught std::length_error: " << e.what() << " Correct! " <<std::endl;
  } catch (const std::exception& e) {
    std::cerr << lines++ << " Wrong exception called:" << e.what() << " Error!" <<std::endl;
    testBTLnk &= false;
  }
  lasd::Vector<double> vec1(RandomNumber(gen) + 1);
  for(lasd::ulong i = 0; i < vec1.Size() - 1; i++){
    vec1[i] = RandomNumber(gen);
  }
  //creo una ripetizione
  vec1[0]++;
  vec1[vec1.Size() - 1] = vec1[0];
  lasd::BinaryTreeLnk<double> btlnk4(std::move(vec1));
  lasd::BinaryTreeVec<double> btvec1(btlnk4);
  double accumulator1 = 0;
  cout<<" Printing new BTLnk :";
  btlnk4.Map(
    [&accumulator1](double dat){
      cout<<dat<<"->";
      accumulator1 += dat;
    }
  );
  cout<<"\n BTLnk's all value sum is: "<<accumulator1<<endl;

  double accumulator2 = 0;
  cout<<" Printing new BTVec :";
  btvec1.Map(
    [&accumulator2](double dat){
      cout<<dat<<"->";
      accumulator2 += dat;
    }
  );
  cout<<"\n BTVec(BTLnk)'s all value sum is: "<<accumulator2<<endl;
  if(accumulator1 == accumulator2) {
    cout<<lines++<<" BTVec & BTLnk are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" BTVec & BTLnk are NOT equals: Error!"<<endl;
    testBTLnk &= false;
  }

  lasd::BST<double> BST1(std::move(btlnk4));
  double accumulator3 = 0;
  cout<<" Printing new BST :";
  BST1.Traverse(
    [&accumulator3](double dat){
      cout<<dat<<"->";
      accumulator3 += dat;
    }
  );
  cout<<"\n BST's all value sum is: "<<accumulator3<<endl;
  if(accumulator2 != accumulator3) {
    cout<<lines++<<" BST & (BTLnk & BTVec) are NOT equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" BST & (BTLnk & BTVec) are equals: Error!"<<endl;
    testBTLnk &= false;
  }

  lasd::Vector<int> vec3(RandomNumber(gen) + 1);
  for(lasd::ulong i = 0; i < vec3.Size(); i++){
    vec3[i] = RandomNumber(gen);
  }
  lasd::BinaryTreeLnk<int> btlnk5(vec3);
  lasd::BinaryTreeVec<int> btvec2(vec3);
  lasd::BinaryTreeLnk<int> btlnk6(btlnk5);
  lasd::BinaryTreeVec<int> btvec3(btvec2);
  if(btlnk5.lasd::BinaryTree<int>::operator==(btvec2)){
    cout<<lines++<<" btlnk and bvec(copy assignament from the same vector) are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" btlnk and bvec(copy assignament from the same vector) are NOT equals: Error!"<<endl;
  }
  if(btlnk6.lasd::BinaryTree<int>::operator==(btvec3)){
    cout<<lines++<<" btlnk(from btvec) and btvec are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" btlnk(from btvec) and btvec are NOT equals: Error!"<<endl;
  }

  lasd::Vector<int>vector(2);
  vector[0] = RandomNumber(gen);
  vector[1] = RandomNumber(gen);
  lasd::BinaryTreeLnk<int>btlnk7(std::move(vector));
  lasd::List<int>lista(btlnk7);
  for(lasd::ulong i=0; i< lista.Size();i++) {
    cout<<lines++<<" extracted value from List(BTLnk): "<<lista[i]<<" Correct!"<<endl;
  }
  lasd::Vector<int>vettore(std::move(btlnk7));
  for(lasd::ulong i=0; i< vettore.Size();i++) {
    cout<<lines++<<" extracted value from Vector(BTLnk): "<<vettore[i]<<" Correct!"<<endl;
  }

  lasd::Vector<int> vettore1((RandomNumber(gen)%10) + 5);
  for(lasd::ulong i = 0; i < vettore1.Size(); i++) {
    vettore1[i] = RandomNumber(gen);
  }
  cout<<lines++<<" MAP VETTORE:";
  vettore1.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  lasd::BinaryTreeLnk<int> bintrelnk(std::move(vettore1));
  cout<<"\n"<<lines++<<" MAP:";
  bintrelnk.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" PREORDERMAP:";
  bintrelnk.PreOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" POSTORDERMAP:";
  bintrelnk.PostOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" INORDERMAP:";
  bintrelnk.InOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" BREADTHORDERMAP:";
  bintrelnk.BreadthMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );

  return testBTLnk;
}


bool TestBST()
{
  bool testBST = true;
  int lines = 1;
  cout<<"\n\nBegin of BST Test: "<<endl;

  lasd::Vector<int> vec1;
  lasd::BST<int> bst1(vec1);
  bst1.Insert(1);
  if(bst1.Max() == 1) {
    cout<<lines++<<" Max is (obtained Max)'"<<bst1.Max()<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" Max is (obtained Min)'"<<bst1.Max()<<": Error!"<<endl;
    testBST &= false;
  }

  lasd::Vector<int> vec2(RandomNumber(gen) + 1);
  for(lasd::ulong i = 0; i < vec2.Size(); i ++) {
    vec2[i] = RandomNumber(gen);
  }
  bst1.Clear();
  bst1.InsertAll(vec2);
  int ExstactedValue = bst1.MaxNRemove();
  while(!bst1.Empty()) {
    if(bst1.Max() > ExstactedValue) {
      break;
      cout<<lines++<<" Previous ExtractedMax '"<<ExstactedValue<<"' > Actual ExtractedMax '"<<bst1.Max()<<"': Error!"<<endl;
      testBST &= false;
    } else {
      cout<<lines++<<" Previous ExtractedMax '"<<ExstactedValue<<"' < Actual ExtractedMax '"<<bst1.Max()<<"': Correct!"<<endl;
    }  
    ExstactedValue = bst1.MaxNRemove();
  }

  lasd::BST<int> bst2;
  if(bst1 == bst2) {
    cout<<lines++<<" Two empty BST are equal: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two empty BST are NOT equal: Error!"<<endl;
    testBST &= false;
  }

  lasd::BST<int> bst3(vec2);
  bst1 = bst3;
  if(bst1 == bst3) {
    cout<<lines++<<" BST and its BST copy assignament are equal: Correct!"<<endl;  
  } else {
    cout<<lines++<<" BST and its BST copy assignament are NOT equal: Error!"<<endl;
    testBST&= false;
  }
  bst2 = std::move(bst3);
  if(bst2 != bst3) {
    cout<<lines++<<" BST and its BST move assignament are NOT equal: Correct!"<<endl;
  } else {
    cout<<lines++<<" BST and its BST move assignament are equal: Erroe!"<<endl;
    testBST &= false;
  }
  if(bst3.Empty()) {
    cout<<lines++<<" Moved BST is now Empty: Correct!"<<endl;
  } else {
    cout<<lines++<<" Moved BST is NOT Empty: Error!"<<endl;
    testBST &= false;
  }
  if(bst1 == bst2) {
    cout<<lines++<<" BST1 and BST2 are equal: Correct!"<<endl;
  } else {
    cout<<lines++<<" BST1 and BST2 are equal: Error!"<<endl;
    testBST &= false;
  }

  lasd::List<std::string> lst1;
  lst1.Insert("a");
  for(int i = 0; i < 3; i++) {
    lst1.InsertAtFront("a" + lst1.Front());
  }
  lasd::BST<std::string> bst4(std::move(lst1));
  if(bst4.Min().length() < bst4.Max().length()){
    cout<<lines++<<" Lenght min '"<<bst4.Min()<<"' < lenght max '"<<bst4.Max()<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" Lenght min '"<<bst4.Min()<<"' > lenght max '"<<bst4.Max()<<"': Error!"<<endl;
    testBST &= false;
  }
  if(bst4.Predecessor("aa") == "a") {
    cout<<lines++<<" 'aa' predecessor is '"<<bst4.Predecessor("aa")<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" 'aa' predecessor is '"<<bst4.Predecessor("aa")<<"': Error!"<<endl;
    testBST &= false;
  }
  if(bst4.Successor("aaa") == "aaaa") {
    cout<<lines++<<" 'aaa' successor is '"<<bst4.SuccessorNRemove("aaa")<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" 'aaa' successor is '"<<bst4.SuccessorNRemove("aaa")<<"': Error!"<<endl;
    testBST &= false;
  }
  if(!bst4.Exists("aaaa")) {
    cout<<lines++<<" 'aaa' successor has been successfully deleted!: Correct!"<<endl; 
  } else {
    cout<<lines++<<" 'aaa' successore has NOT been deleted!: Error!"<<endl;
  }
  bst4.Clear();
  if(bst4.Empty()) {
    cout<<lines++<<" BST has been successfully cleared!: Correct!"<<endl; 
  } else {
    cout<<lines++<<" BST has NOT been cleared!: Error!"<<endl;
  }
  
  lasd::SortableVector<int> vec3(RandomNumber(gen) + 3);
  for(lasd::ulong i = 0; i < vec3.Size(); i++) {
    vec3[i] = RandomNumber(gen);
  }
  lasd::BST<int> bst5(vec3);
  cout<<"   Print BST with Random Values: \n";
  cout<<"   ";
  bst5.Traverse(
    [](const int& dat){
        cout<<dat<<"->";
    }
  );
  cout<<endl;
  if(bst5.Root().Element() == vec3[0]) {
    cout<<lines++<<" extracted BST Root is '"<<bst5.Root().Element()<<"'(expected '"<<vec3[0]<<"'): Correct!\n";
  } else {
    cout<<lines++<<" extracted BST Root is '"<<bst5.Root().Element()<<"'(expected '"<<vec3[0]<<"'): Error!\n";
    testBST &= false;   
  }
  vec3.Sort();
  if(vec3[0] == bst5.Min()) {
    cout<<lines++<<" extracted BST Min is '"<<bst5.Min()<<"'(expected '"<<vec3[0]<<"'): Correct!\n";
  } else {
    cout<<lines++<<" extracted BST Min is '"<<bst5.Min()<<"'(expected '"<<vec3[0]<<"'): Error!\n";
    testBST &= false;
  }
  if(bst5.Min() == bst5.Predecessor(bst5.Successor(bst5.Min()))){
    cout<<lines++<<" predecessor of Successor's Min is'"<<bst5.Predecessor(bst5.Successor(bst5.Min()))<<"'(expected '"<<bst5.Min()<<"'): Correct!\n";
  } else {
    cout<<lines++<<" predecessor of Successor's Min is'"<<bst5.Predecessor(bst5.Successor(bst5.Min()))<<"'(expected '"<<bst5.Min()<<"'): Error!\n";
    testBST &= false;
  }
  if(vec3[vec3.Size() - 1] == bst5.Max()) {
    cout<<lines++<<" extracted BST Max is '"<<bst5.Max()<<"'(expected '"<<vec3[vec3.Size() - 1]<<"'): Correct!\n";
  } else {
    cout<<lines++<<" extracted BST Max is '"<<bst5.Max()<<"'(expected '"<<vec3[vec3.Size() - 1]<<"'): Error!\n";
    testBST &= false;
  }
  if(bst5.Max() == bst5.Successor(bst5.Predecessor(bst5.Max()))){
    cout<<lines++<<" successor of Predecessor's Min is'"<<bst5.Successor(bst5.Predecessor(bst5.Max()))<<"'(expected '"<<bst5.Max()<<"'): Correct!\n";
  } else {
    cout<<lines++<<" successor of Predecessor's Min is'"<<bst5.Successor(bst5.Predecessor(bst5.Max()))<<"'(expected '"<<bst5.Max()<<"'): Error!\n";
    testBST &= false;
  }


  try{
    bst5.Root();
  } catch (const std::length_error& e) {
    // Gestione dell'eccezione
    std::cerr << lines++ << " Caught std::length_error: " << e.what() << " Correct! " <<std::endl;
  } catch (const std::exception& e) {
    std::cerr << lines++ << " Wrong exception called:" << e.what() << " Error!" <<std::endl;
    testBST &= false;     
  }


  bst5.Clear();
  if(bst5.Empty()) {
    cout<<lines++<<" BST has been successfully cleared!: Correct!"<<endl;
  } else {
    cout<<lines++<<" BST has NOT been cleared!: Error!"<<endl;
  }


  if(bst5.Insert(3)){
    cout<<lines++<<" Inserted value 3: Correct!"<<endl;
  }else {
    cout<<lines++<<" Not inserted value 3: Error!"<<endl;
    testBST &= false;
  }
  if(bst5.Insert(7)) {
    cout<<lines++<<" Inserted value 7: Correct!"<<endl;
  }else {
    cout<<lines++<<" Not inserted value 7: Error!"<<endl;
    testBST &= false;
  }
  try {
    bst5.Successor(8);   
  } catch (const std::length_error& e) {
    // Gestione dell'eccezione
    std::cerr << lines++ << " Caught std::length_error: " << e.what() << " Correct! " <<std::endl;
  } catch (const std::exception& e) {
    std::cerr << lines++ << " Wrong exception called:" << e.what() << " Error!" <<std::endl;
    testBST &= false;
  }
  if(bst5.Successor(6) == 7) {
    cout<<lines++<<" '6' successor is '7': Correct!"<<endl;
  } else {
    cout<<lines++<<" '6' is not '7': Error!"<<endl;
    testBST &= false;   
  }

  lasd::Vector<int>vettore(bst5);
  for(lasd::ulong i=0; i< vettore.Size();i++) {
    cout<<lines++<<" extracted value from Vector(BST): "<<vettore[i]<<endl;
  }
  lasd::List<int>lista(bst5);
  for(lasd::ulong i=0; i< lista.Size();i++) {
    cout<<lines++<<" extracted value from List(BST): "<<lista[i]<<endl;
  }

  lasd::Vector<int> vettore1((RandomNumber(gen)%10) + 5);
  for(lasd::ulong i = 0; i < vettore1.Size(); i++) {
    vettore1[i] = RandomNumber(gen);
  }
  cout<<lines++<<" TRAVERSE VETTORE:"; 
  vettore1.Traverse(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  lasd::BST<int> binserTree(std::move(vettore1));
  cout<<lines++<<" TRAVERSE:";
  binserTree.Traverse(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" PREORDERTRAVERSE:"; 
  binserTree.PreOrderTraverse(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" POSTORDERTRAVERSE:"; 
  binserTree.PostOrderTraverse(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" INORDERTRAVERSE:"; 
  binserTree.InOrderTraverse(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" BREADTHORDERTRAVERSE:"; 
  binserTree.BreadthTraverse(
    [](int dat){
      cout<<"->"<<dat;
    }
  );


  return testBST;
}

























void TestEsercizio1(){
  cout<<(TestCostruttori()? "\nPASSATO\n" : "\nNON Passato\n");
  cout<<(TestAssegnazioni()? "\nPASSATO\n" : "\nNON Passato\n");
  cout<<(TestDictionaryFunctions()? "\nPASSATO\n" : "\nNON Passato\n");
  cout<<(TestSort()? "\nPASSATO\n\n" : "\nNON Passato\n\n");
  cout<<(TestQueueVec()? "\nPASSATO\n\n" : "\nNON Passato\n\n");
}


void TestEsercizio2(){
  bool testIteratori = TestIteratori();
  cout<<"Iterator Test: ", testIteratori ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
 bool testBST = TestBST();
  cout<<"\nBST Test: ", testBST ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  bool testBTVec = TestBTVec();
  cout<<"\nBTVec Test: ", testBTVec ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  bool testBTLnk = TestBTLnk();
  cout<<"\nBTLnk Test: ", testBTVec ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  if(testBST && testIteratori && testBTVec && testBTLnk){
    cout<<"\nMyTest Esercizio2 : Passato!";
  } else {
    cout<<"\nMyTest Esercizio2 : NON Passato!";
  }
}

