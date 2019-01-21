#define align4(x) (((((x)-1)>>2)<<2)+4)
#define BLOCK_SIZE 12

typedef struct s_block *t_block;

struct s_block{
    size_t   size;//数据区大小
    t_block  next;//指向下个块的指针
    int      free;//是否是空闲块
    char     data[1];//虚拟字段，表示数据块的第一个字节，长度不计入meta
};

t_block find_block(t_block *last, size_t size)
{
    t_block b = base;
    while(b && !(b->free && b->size >= size))
    {
        *last = b;
        b = b->next;
    }
    
    return b;
}

t_block extend_heap(t_block last, size_t size)
{
    t_block b;
    b = sbrk(0);//定位到当前break位置
    if(sbrk(sizeof(struct s_block) + size) == (void*)-1)//调整break位置
        return NULL;
    b->size = size;
    b->next = NULL;
    if(last)//这个last是指向extend之前最后一个block
        last->next = b;//新开辟的block挂载在链表中
    b->free = 0;
    
    return b;
}

//b是要分裂的block，size是申请的内存大小
//分裂后b成了分配后的block
void split_block(t_block b, size_t size)
{
    t_block newblock;//新的空闲block = 要分裂的block - 申请分配出去的内存
    newblock = b->data + size;//将new定位到剩下的数据块区域
    //分裂的原block-分配出去的内存大小-block结构体本身大小
    newblock->size = b->size - size - BLOCK_SIZE;
    newblock->next = b->next;//链表插入
    newblock->free = 1;//空闲标记可用
    b->size = size;
    b->next = newblock;//链表插入
}

void *base = NULL;

void *malloc(size_t size)
{   
    t_block b, last;
    size_t s;

    s = align4(size);
    if(base)
    {
        //first find a block
        last = base;
        b = find_block(&last, s);
        if(b)
        {
            //can we split
            if((b->size - s) >= (BLOCK_SIZE + 8))
                split_block(b, s);
            b->free = 0;
        }
        else
        {
            //no fitting block, extend the heap
            b = extend_heap(last, s);
            if(!b)
                return NULL;
        }
    }
    else
    {
        //first time
        b = extend_heap(NULL, s);
        if(!b)
            return NULL;
        base = b;
    }
    
    return b->data;
}
