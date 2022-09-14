/**
 * 顺序表
 */
#include <stdio.h>

#define MAXSIZE 5
#define ELEM_TYPE int

typedef enum {ERROR, OK} Status;
typedef enum {FALSE, TRUE} Bool;

typedef struct {
    ELEM_TYPE data[MAXSIZE];
    int length;
} SeqList;

/**
 * 初始化列表
 * @param L
 */
void initList(SeqList *L);

 /**
  * 获取表长度
  * @param L
  * @param length
  * @return
  */
Status getLength(SeqList *L, int *length);

 /**
  * 是否为空
  * @param L
  * @param ret
  * @return
  */
Status isEmpty(SeqList *L, Bool *ret);

/**
 * 获取指定元素位置
 * @param L
 * @param elem
 * @param retPos
 * @return 状态值 成功 TRUE  失败 ERROR
 */
Status getElemLocation(SeqList *L, ELEM_TYPE elem, int *retPos);

/**
 * 获取元素
 * @param L
 * @param pos 元素序号 i >= 1
 * @param retElem 返回元素值
 * @return 状态值 成功 TRUE  失败 ERROR
 */
Status getElem(SeqList *L, int pos, ELEM_TYPE *retElem);

/**
 * 插入元素
 * @param L
 * @param index 索引 i >= 0
 * @param elem
 * @return
 */
Status insertElem(SeqList *L, int index, ELEM_TYPE elem);

/**
 * 删除元素
 * @param L
 * @param index 索引 i >= 0
 * @return
 */
int deleteElem(SeqList *L, int index);

/**
 * 打印列表
 * @param L
 * @return
 */
int printList(SeqList *L);

void initList(SeqList *L){
    L->length = 0;
}

Status getLength(SeqList *L, int *length){
    if(&(L->length) == NULL){
        printf("List Not Init\n");
        return ERROR;
    }
    *length = L->length;
    return OK;
}

Status isEmpty(SeqList *L, Bool *ret){
    int length;
    if(getLength(L, &length)){
        *ret = length ? FALSE :TRUE;
        return OK;
    } else{
        return ERROR;
    }
}

Status getElemLocation(SeqList *L, ELEM_TYPE element, int *retPos){
    Bool is_empty;
    if(!isEmpty(L, &is_empty) || is_empty){
        return ERROR;
    }

    int i;
    int length;

    if(!getLength(L, &length)){
        return ERROR;
    }

    for (i = 0; i < length && L->data[i] != element; ++i);

    if(L->length == i && L->data[i] != element){
        printf("Element {%d} Not Found\n", element);
        return ERROR;
    }

    *retPos = i + 1;
    return OK;
}

Status getElem(SeqList *L, int pos, ELEM_TYPE *retElem){
    if(L->length){

    }
}

Status insertElem(SeqList *L, int pos, ELEM_TYPE element){
    if(pos < 1 || pos > L->length + 1){
        printf("Position Not Exist\n");
        return ERROR;
    }

    if(L->length >= MAXSIZE){
        printf("List Is Full\n");
        return ERROR;
    }

    for (int i = L->length; i >= pos; --i) {
        L->data[i] = L->data[i - 1];
    }

    L->data[pos - 1] = element;
    L->length++;
    return OK;
}

int deleteElem(SeqList *L, int pos){

    return 0;
}

int printList(SeqList *L){

}

/**
 * 程序入口
 * @return
 */
int main(){
    SeqList L;
    SeqList *pL = &L;
    initList(pL);

    ELEM_TYPE items[] = {11, 22, 33, 44, 55};
    int i;
    int length = sizeof(items) / sizeof(ELEM_TYPE);
    for (i = 1; i <= length && insertElem(pL, i, items[i - 1]); ++i);

    length = 0;
    if(getLength(pL, &length)){
        printf("length of seq_list is : %d\n", length);
    }

    int pos = 0;
    ELEM_TYPE element = 22;
    if(getElemLocation(pL, element, &pos)){
        printf("pos of {%d} is : %d\n", element, pos);
    }



    LABEL_END:return 0;
}
