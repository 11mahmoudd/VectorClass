#ifndef VECTORCLASS_H
#define VECTORCLASS_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
class VectorClass
{
private:
    T* vect;
    int sizee ,capacityy;
public:
    VectorClass(int num)
    {
        capacityy=num;
        vect=new T [capacityy];
        sizee=0;
    }
    VectorClass(T* arr, int n) {
        sizee = n;
        vect = new T[sizee];
        for (int x = 0; x < sizee; x++) {
            vect[x] = arr[x];
        }
    }

    VectorClass(const VectorClass &new_vect)
        {
            sizee = new_vect.sizee;
            capacityy = new_vect.capacityy;
            vect = new T[capacityy];
            for (int x = 0; x < sizee; x++) {
                vect[x] = new_vect.vect[x];
            }

        }

        VectorClass &operator=(const VectorClass& new_vect)
        {
            delete [] vect;
            sizee=new_vect.sizee;
            capacityy=new_vect.capacityy;
            vect = new T[capacityy];
            for (int x= 0 ;x < sizee ; x++)
            {
                vect[x] = new_vect.vect[x] ;


            }
            return *this;
        }

        VectorClass &operator=(const VectorClass&& new_vect)
        {
            delete [] vect;
            sizee= move (new_vect.sizee);
            capacity= move(new_vect.capacityy);
            vect= new T[capacityy];
            for(int x= 0 ;x < sizee ; x++)
            {
                vect[x]= move(new_vect.vect[x]);
            }
            return *this;
        }

        T& operator[](int i)
        {
            if( i >= 0 || i <= sizee-1)
            {
                return vect[i];
            }
            try
            {
                if(i > sizee-1 || i <0 )
                {
                    throw 0;
                }
            }
            catch (int n)
            {
                cout<<"wrong index"<<endl;
            }

        }

        bool operator==(const VectorClass<T>& vec)
        {
            if (sizee == vect.sizee)
            {
                for(int x = 0 ; x < sizee ; x++)
                {
                    if(vect[x] != vec.vect[x] )
                    {
                        return false;
                        break;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        bool operator< (const VectorClass<T>& vec)
        {
            if(sizee==vec.sizee)
            {
                for(int x = 0 ; x < sizee ; x++)
                {
                    if(vect[x]<vec.vect[x])
                    {
                        return true;
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        int size() const
        {
            return sizee;
        }

        int capacity() const
        {
            return capacityy;
        }

        int resize()
        {
            if(sizee == capacityy)
            {
                capacityy *=2;
                T* new_vect = new T[capacityy];
                for(int x = 0 ; x < sizee ; x++)
                {
                    new_vect[x]=vect[x];
                }
                delete vect;
                for(int x = 0 ; x < sizee ; x++)
                {
                    vect[x]=new_vect[x];
                }

            }
            return capacityy ;
        }

        bool empty()
        {
            if(sizee==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


        friend ostream& operator << (ostream& out, VectorClass<T> vc)
        {
            out << "{";
            for(int x = 0 ; x < vc.sizee ; x++)
            {
                out<<vc.vect[x];
                if(x != vc.sizee -1){
                    out << "," ;
                }
            }
            out << "}";
            return out;

        }

        virtual ~VectorClass()
        {

            delete [] vect;
        }

        void insert(T* ite,int V )
        {
            if(ite < this-> begin()|| ite > this-> end()){
                cout << "out of range" ;

            }

            else{
                this->push_back(0);
                int ix = ite - begin()  ;
                for (int i = sizee-1 ; i > ix ; i--){
                    this-> vect[i] = this->vect[i-1];
                }
                this->vect[ix] = V;

            }

        }

        int push_back (T var)
        {
            if(sizee < capacityy){
                vect[sizee++] = var;
            }
            else

            {
                T* newvect = new T[capacityy*2];
                capacityy *= 2;

                for (int i=0; i < sizee ; i++){
                    newvect[i] = vect[i];

                }
                delete[] vect;
                vect = new T[capacityy];
                for (int i =0 ; i < sizee ; i++){
                    vect[i]= newvect[i];
                }
                delete[] newvect;
                vect[sizee+1] = var;

            }
            return sizee;

        }
        T* begin()
        {
            return this->vect;
        }
        T* end()
        {
            return this->begin()+size()-1;
        }


        void clear()
        {
            for(int i=0 ;i < this->size();i++)
            {
                this->vect[i]= T();
            }

            this->sizee=0;
        }

        T pop_back() {
            T* newvect = new T[capacityy] ;
            for (int x = 0 ; x < sizee-1 ;x++) {
                newvect[x] = vect[x] ;

            }
            T z = vect[sizee -1] ;

            delete[]vect ;
            vect = new T[capacityy] ;
            sizee = sizee - 1 ;
            for (int x = 0 ; x < sizee ; x++) {
                vect[x] = newvect[x] ;

            }
            delete[]newvect ;
            return z ;
        }
        void erase(T* ite){
            if(ite < this-> begin() || ite > this->end() ) {
                cout << "not in range"<<endl;
            }
            else {
                int index=ite-begin();
                for(int i=index+1;i< this->size();i++) {
                    this->vect[i - 1] = this->vect[i];

                }
                this->sizee--;
            }
        }
        void erase(T* ite1 , T* ite2){
            if(ite1 < this-> begin() || ite2 > this->end() ) {
                cout << "not in range"<<endl;
            }

            else {

                if (ite2<ite1)
                    return;
                int startindex=ite1-begin();
                int endindex=ite2-begin();
                int counter=0;
                for(int i = endindex+1;i< this->size();i++) {
                    this->vect[startindex + counter] = this->vect[i];
                    counter++;
                }
                this->sizee-=endindex-startindex+1;
            }
        }



    };

#endif // VECTORCLASS_H
