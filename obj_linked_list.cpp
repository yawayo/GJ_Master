#include "obj_linked_list.h"

obj_LinkedList::obj_LinkedList()
{
    size = 0;
    start = 0;
    memset(data, 0, sizeof(Obj_inf) * MAX_NODE_NUM);
}
obj_LinkedList::~obj_LinkedList()
{
    size = 0;
    start = 0;
    memset(data, 0, sizeof(Obj_inf) * MAX_NODE_NUM);
}
bool obj_LinkedList::isEmpty() const
{
    if(size == 0)
        return true;
    else
        return false;
}
int obj_LinkedList::getsize()
{
    return size;
}
const Obj_inf& obj_LinkedList::getLast() const
{
    return data[(start + size - 1) % MAX_NODE_NUM];
}
void obj_LinkedList::addLast(const Obj_inf node)
{
    memcpy(&data[(start + size) % MAX_NODE_NUM], &node, sizeof(Obj_inf));
    size++;

    if(getsize() > 100)
        remove_front();
}
void obj_LinkedList::remove_front()
{
    start++;
    size--;
}
void obj_LinkedList::remove_all()
{
    size = 0;
    start = 0;
    memset(data, 0, sizeof(Obj_inf) * MAX_NODE_NUM);
}
