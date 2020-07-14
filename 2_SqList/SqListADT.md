ADT SqList{
	数据对象{
	}
	数据关系
	操作类型{
		Status DestoryList();
		//删除线性表

		Status ClearList();
		//清空线性表

		Status EmptyList();
		//return List Empty or not

		Status GetElem();
		//return elem

		Status ListLength();
		//return list length

		Status PriorElem();
		//return prior elem

		Status NextElem();
		//return next elem

		Status ListInsert();
		//Insert elem into location

		Status DeleteList();
		//delete list
		
		Status ListTraverse();
	}
}
