#include<iostream> 
#include<string> 
using namespace std;
class MyData 
{     public:
       int  GetData()
       {
           return this->data;
       }
        void SetData(int num)        {
           this->data=num;
        }
        MyData()
        {
            this->data=0;
        }
       MyData(int num)
        {
          this->data=num;
        }
        ~MyData()
        {
  
       }
     private:
        int data;
 };
 
class CGoods
 {
     public:
         void RegisterGoods(string name,int count, float price)
        {
            this->name=name;
            this->count=count;
            this->price=price;
        }

         void SetName(string name) 
			{  
			 this->name=name;
          }
         void SetCount(int count)
        {
             this->count=count;
         }
         void SetPrice(float price)
         {
            this->price=price;
         }
         string GetName()
         {
             return this->name;
         }
         int GetCount()
         {
            return this->count;
         }
         float GetPrice()
         {
                       return this->price;
         }
         float GetTotal_price()
         {
             return this->count*this->price;
        }
     private:
         string name;
         int count;
        float price;
         float total_price;
  
 };
 int main()
 {
   //  MyData d1,d2;
   CGoods g1,g2;
   g1.RegisterGoods("abc",15,12.4);
  cout<< g1.GetName()<<endl;
  cout<< g1.GetCount()<<endl;
  cout<< g1.GetPrice()<<endl;
  cout << g1.GetPrice() << endl;
  g1.SetName("bcd");
  cout << g1.GetName() << endl;
     return 0;
 }

                                                                        
