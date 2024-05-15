// 如果可用空间还有就调用对象的构造函数并使用空间的尾增加
// 没有空间就重新申请一个更大的空间, 然后进行插入
template <class T, class Alloc>
void vector<T, Alloc>::push_back(const T& x) 
{
      // 如果还没有到填满整个数组, 就在数据尾部插入
      if (finish != end_of_storage) 
      {
        	construct(finish, x);
        	++finish;
      }
    // 数组被填充满, 调用insert_aux必须重新寻找新的更大的连续空间, 再进行插入
      else
          insert_aux(end(), x);
}

// insert_aux实现
template <class T, class Alloc>
void vector<T, Alloc>::insert_aux(iterator position, const T& x) 
{
     // 如果数组还有备用空间, 就直接移动元素, 再将元素插入过去, 最后调整finish就行了.
  if (finish != end_of_storage) 
  {
      // 调用构造, 并将最后一个元素复制过去, 调整finish
    construct(finish, *(finish - 1));
    ++finish;
    T x_copy = x;
      // 将插入元素位置的后面所有元素往后移动, 最后元素插入到位置上.
    copy_backward(position, finish - 2, finish - 1);
    *position = x_copy;
  }
   // 没有备用空间, 重新申请空间再将元素拷贝过去同时执行插入操作
  else {
    const size_type old_size = size();
    const size_type len = old_size != 0 ? 2 * old_size : 1;	// 重新申请空间原始空间的两倍的空间

    iterator new_start = data_allocator::allocate(len);
    iterator new_finish = new_start;
    __STL_TRY {
        // 进行分段将原始元素拷贝新的空间中, 这样也就实现了插入操作
      new_finish = uninitialized_copy(start, position, new_start);
      construct(new_finish, x);
      ++new_finish;
      new_finish = uninitialized_copy(position, finish, new_finish);
    }

#       ifdef  __STL_USE_EXCEPTIONS 
    catch(...) {
      destroy(new_start, new_finish); 
      data_allocator::deallocate(new_start, len);
      throw;
    }
#       endif /* __STL_USE_EXCEPTIONS */
      // 释放掉原来的空间, 调整新的3个迭代器的位置
    destroy(begin(), end());
    deallocate();
    start = new_start;
    finish = new_finish;
    end_of_storage = new_start + len;
  }
}