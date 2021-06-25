//#include <iostream>
//using namespace std;
//
//int Delete_info(PTR& First, int x)
//{
//    PTR p;
//    int dem = 0;
//    // if (First==NULL ) return 0;
//    while (First != NULL && First->info == x)
//    {
//        p = First;
//        First = p->next;
//        delete p;
//        dem++;
//    }
//    // 2 2 2
//    if (First == NULL) return dem;
//    for (p = First; p->next != NULL; )
//    {
//        if (p->next->info == x)
//        {
//            Delete_after(p);
//            dem++;
//        }
//        else p = p->next;
//    }
//    return dem;
//}
//int main()
//{
//    return 0;
//}
//
//
////-------------------------------------------------------
//
//[9:39 AM] Đức Lê Huỳnh(Khách)
//int Ghep2DS(DS ds2, DS& ds1, int inx) {
//    ​​​​
//
//        Node temp;
//
//    int flag = 0;
//
//    if (ds2.phead == NULL || ds1.phead == NULL)
//
//        return 0;
//
//    for (PTR p = ds1.phead, int i = 1;  i < inx p!= NULL; p = p->next, i++)
//
//        if (i == inx) {
//            ​​​​
//
//                temp = p->next;
//
//            p->next = ds2.phead;
//
//            ds2.ptail = temp;
//
//            return 1;
//
//        }​​​​
//
//            if (flag == 0) {
//                ​​​​
//
//                    return 0;
//
//            }​​​​   
//
//}​​​​
//
//[9:40 AM] Đức Lê Huỳnh(Khách)
//typedef struct node {
//                ​​​​
//
//                    int info;
//
//                node* next;
//
//            }​​​​; typedef node* Node;
//
