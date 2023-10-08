#include <iostream>
#include <algorithm>
using namespace std;

/*
���Ա�:
����:
1. ��ʼ��
2. �ж��Ƿ�Ϊ��
3. �ж��Ƿ�Ϊ��
4. ������Ա�
5. ����Ԫ��
6. ɾ��Ԫ��
7. ��λԪ��(����Ԫ��λ��)
8. �õ�Ԫ��(����һ������,�Ա������и�ֵ)
8. �޸�Ԫ��
9. ���Ա���
* 10. ��̬����
*/

#define MAX_SIZE 256
template<class T>
class SeqList
{
private:
    T data[MAX_SIZE];
    int length;

public:
    SeqList();
    ~SeqList();

    void initList();
    bool isEmpty();
    bool isFull();
    void clearList();
    void insertElem(int index, T data);
    void deleteElem(int index);
    int findElem(T data);
    int getElem(int index);
    void updateElem(int index, T data);
    int getLength();
    void printList();
};

int main()
{
    SeqList<int>* sList = new SeqList<int>();
    
    sList->insertElem(1, 10);
    sList->insertElem(2, 40);
    sList->insertElem(3, 30);
    sList->insertElem(4, 280);

    sList->deleteElem(2);

    cout << "(30)'s index is " << sList->findElem(30) << endl;
    cout << "index 3 is " << sList->getElem(3) << endl;

    sList->updateElem(3, 200);

    cout << "length = " << sList->getLength() << endl;
    sList->printList();

    return 0;
}

template <class T>
SeqList<T>::SeqList()
{
    this->initList();
}

template <class T>
SeqList<T>::~SeqList()
{
}

template <class T>
void SeqList<T>::initList()
{
    this->length = 0;
}

template <class T>
bool SeqList<T>::isEmpty()
{
    return length == 0 ? true : false;
}

template <class T>
bool SeqList<T>::isFull()
{
    return length == MAX_SIZE ? true : false;
}

template <class T>
void SeqList<T>::clearList()
{
    this->length = 0;
}

template <class T>
void SeqList<T>::insertElem(int index, T data)
{
    if(index < 1 || index > length + 1 || this->isFull())
    {
        cout << "λ�ò��Ϸ�����������" << endl;
        return;
    }
    for (int i = index - 1; i < this->length; i++)
    {
        this->data[i + 1] = this->data[i];
    }
    this->data[index - 1] = data;
    this->length++;
}

template <class T>
void SeqList<T>::deleteElem(int index)
{
    if(index < 1 || index > length || this->isEmpty())
    {
        cout << "λ�ò��Ϸ�������Ϊ��" << endl;
        return;
    }

    for (int i = index; i < length; i++)
    {
        this->data[i - 1] = this->data[i];
    }
    this->length--;
}

template <class T>
int SeqList<T>::findElem(T data)
{
    int count = 1;
    for(T _data : this->data)
    {
        if(_data == data)
        {
            return count;
        }
        count++;
    }
    return -1;
}

template <class T>
int SeqList<T>::getElem(int index)
{
    return this->data[index - 1];
}

template <class T>
void SeqList<T>::updateElem(int index, T data)
{
    if(index < 1 || index > length || this->isEmpty())
    {
        cout << "λ�ò��Ϸ�������Ϊ��" << endl;
        return;
    }
    this->data[index - 1] = data;
}

template <class T>
int SeqList<T>::getLength()
{
    return this->length;
}

template <class T>
void SeqList<T>::printList()
{
    for (int i = 0; i < this->length; i++)
    {
        cout << this->data[i] << " ";
    }
    cout << endl;
}
