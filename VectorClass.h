#ifndef VECTORCLASS_H
#define VECTORCLASS_H

#include <bits/stdc++.h>

using namespace std;
// Creating a template to use any data type in this program.
//data type is called T
template <typename T>
//creating class.
class VectorClass
{
    // Create 3 private variables a T array named vect and 2 integer variables sizee and capacityy.
    private:
        T* vect;
        int sizee ,capacityy;
    protected:
    public:
        //Constructor that takes integer parameter.
        VectorClass(int num)
        {
            //set the capacity of the vector.
            capacityy=num;
            vect=new T [capacityy];
            sizee=0;
        }
        //Constructor that takes array and integer parameters.
        VectorClass(T* arr, int n)
        {
            //set size of the vector and fill the vector with elements in given array.
            sizee=n;
            vect= new T [sizee];
            for(int x=0;x<sizee;x++)
            {
                vect[x]=arr[x];
            }
        }
        //Constructor that takes class data type parameter.
        VectorClass(const VectorClass& new_vect)
        {
            //Fill the new vector with old vector and set the new vector size and capacity as the old one.
            sizee=new_vect.sizee;
            capacityy=new_vect.capacityy;
            vect= new T[capacityy];
            for(int x=0;x<sizee;x++)
            {
                vect[x]= new_vect.vect[x];
            }

        }
        // Copy assignment.
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
        // Move assignment.
        VectorClass &operator=(const VectorClass&& new_vect)
        {
            delete [] vect;
            sizee= move (new_vect.sizee);
            capacity= move(new_vect.capacity);
            vect= new T[capacity];
            for(int x= 0 ;x < sizee ; x++)
            {
                vect[x]= move(new_vect.vect[x]);
            }
            return *this;
        }

        // Access item by reference.
         // Throw an exception if out of range.
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
                cout<<"wrong index, out of range. "<<endl;
            }

        }

        // Add item to end of vector & return # of items
        // Increase capacity of needed
        int push_back(T element)
        {
            resize();
            vect[sizee++] = element ;
            return sizee ;
        }

        T pop_back()
        {

        }

        // Return true if a vector ==  another vector.
        bool operator ==(const VectorClass<T>& vec)
        {
            if (sizee == vec.sizee)
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

        // Compares item by item.
        // Return true if first different item in this is < in other.
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
            else if(sizee < vec.sizee)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // Return current size of vector.
        int size() const
        {
            return sizee;
        }

        // Return size of current allocated array.
        int capacity() const
        {
            return capacityy;
        }

        // Relocate to bigger space.
        int resize()
        {
            if(sizee == capacityy)
            {
                capacityy *=2;
                T* new_vec = new T[capacityy];
                for(int x = 0 ; x < sizee ; x++)
                {
                    new_vec[x]=vect[x];
                }
                delete vect;
                for(int x = 0 ; x < sizee ; x++)
                 {
                     vect[x]=new_vec[x];
                 }

            }
            return capacityy ;
        }

        // Return true if size is 0.
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

        //Overload operator << to print the vector by cout.
        friend ostream& operator << (ostream& out, VectorClass<T> vec)
        {
            for(int x = 0 ; x < vec.sizee ; x++)
            {
                out<<vec.vect[x]<<" ";
            }
            return out;

        }

        // Delete allocated memory
        virtual ~VectorClass()
        {
            delete [] vect;
        }




};

#endif // VECTORCLASS_H
