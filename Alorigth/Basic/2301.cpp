#include <iostream>
#include <limits.h>

using namespace std;

struct NODE{
   int Number;
   NODE *Next;
};

NODE * MakeList(int*, int);
NODE *JoinTwoList(NODE*, NODE*);

int main(){
   int Arr1[]={2,3,5,9};
   int Arr2[]={4,6,7,11,16};
   NODE *Head1, *Head2;
   Head1=MakeList(Arr1,sizeof(Arr1)/sizeof(int));
   Head2=MakeList(Arr2,sizeof(Arr2)/sizeof(int));
   NODE *Head = JoinTwoList(Head1, Head2);
   cout << "Head";
   for(NODE* p1=Head->Next; p1!=NULL; p1=p1->Next){
      cout << " -> " << p1->Number;
   }
   return 0;
}


NODE *JoinTwoList(NODE *Head1, NODE *Head2){
	 if (Head1->Next == NULL && Head2->Next == NULL) return NULL;
    Head1 = Head1->Next;
    Head2 = Head2->Next;
    
    NODE *Head = new NODE, *x;
    Head->Next=NULL;
    Head->Number=INT_MAX;
    x = Head;
    
    while (Head1 != NULL || Head2 != NULL){
        x->Next = new NODE;
        x= x->Next;
        if (Head1 == NULL) { 
            x->Number = Head2->Number;
            Head2 = Head2->Next;
        }
        else if (Head2 == NULL) {
            x->Number = Head1->Number;
            Head1 =Head1->Next;
        }
        else {
            x->Number = (Head1->Number < Head2->Number) ? Head1->Number : Head2->Number;
            if (Head1->Number < Head2->Number) Head1 = Head1->Next;
            else Head2 = Head2->Next;
        }
       
        x->Next = NULL;
    }
    return Head;
// Выполнить слияние списков с головами Head1 и Head2
// Функция возвращает указатель на голову списка,
// являющегося результатом слияния
// ............................
}



NODE * MakeList(int Arr[], int n){
// Эта функция создаёт один список
// Arr - массив чисел, которые должны быть помещены в список
// n - их количество
NODE *Head=new NODE,*x;
Head->Next=NULL; //Явно указываем на NULL
Head->Number=INT_MAX; // Условное значение головы
x=Head;
// Создание собственно списка
for (int i = 0; i < n; i++) {
	x->Next=new NODE;
	x=x->Next;
	x->Number=Arr[i];
	x->Next = NULL;
}
return Head;
} 