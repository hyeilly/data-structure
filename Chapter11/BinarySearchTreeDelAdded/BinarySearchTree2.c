#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree3.h"
#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = NULL; // parent node
    BTreeNode * cNode = *pRoot; // current node
    BTreeNode * nNode = NULL; // new node

    while(cNode != NULL)
    {
        if(data == GetData(cNode))
            return;
        pNode = cNode;
        
        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    if(pNode != NULL)
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else
    {
        *pRoot = nNode;
    }
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst; // current node
    BSTData cd; // cureent data

    while(cNode != NULL)
    {
        cd = GetData(cNode);
        
        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
    BTreeNode * pVRoot = MakeBTreeNode(); // 가상 루트 노드 만들기

    BTreeNode * pNode = pVRoot; // parent node
    BTreeNode * cNode = *pRoot; // current node
    BTreeNode * dNode; // delete node

    ChangeRightSubTree(pVRoot, *pRoot); // 진짜 루트노드가 가상 루트노드의 오른쪽 자식이 되게끔 함

    // 삭제 대상인 노드를 탐색
    while(cNode != NULL && GetData(cNode) != target)
    {
        // cNode의 부모 노드를 pNode가 가리키게 해야하기 때문에 이 부분을 BSTSearch 함수의 호출로 대신할 수 없음
        pNode = cNode;
        
        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    if(cNode == NULL) // 삭제 대상이 존재하지 않는다면
        return NULL;

    dNode = cNode; // 삭제 대상을 dNode가 가리키게 함 

    // dNode와 pNode는 각각 삭제할 노드와 이의 부모를 가리키는 포인터 변수
    // 첫번째 경우 : 삭제 대상이 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode) // 삭제할 노드가 왼쪽 자식 노드라면
            RemoveLeftSubTree(pNode); // 왼쪽 자식 노드 트리에서 제거
        else // 삭제할 노드가 오른쪽 자식 노드라면
            RemoveRightSubTree(pNode); // 오른쪽 자식 노드 트리에서 제거
    }
    // 두번째 경우 : 삭제 대상이 하나의 자식 노드를 가짐 
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode * dcNode; // 삭제 대상의 자식 노드 가리킴 
        
        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);
        
        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    // 세번째 경우 : 두 개의 자식 노드를 모두 갖는 경우
    else
    {
        BTreeNode * mNode = GetRightSubTree(dNode); // 대체 노드 가리킴
        BTreeNode * mpNode = dNode; // 대체 노드의 부모 노드를 가리킴
        int delData;
        // 삭제 대상의 대체 노드를 찾음
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        // 대체 노드에 저장된 값을 삭제할 노드에 대입
        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));
        // 대체 노드의 부모 노드와 자시 노드를 연결
        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        dNode = mNode;
        SetData(dNode, delData); // 백업 데이터 복원
    }
    // 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot); // 루트 노드의 변경을 반영
    
    free(pVRoot); // 가상 루트 노드의 소멸
    return dNode; // 삭제 대상의 반환
}

void ShowIntData(int data)
{
    printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowIntData);
}