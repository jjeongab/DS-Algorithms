class Solution:
    def heap_sort(self, lst : List[int])-> None:
        def max_heapify(heap_size, index):
            left, right = 2 * index + 1, 2 * index + 2
            largest = index
            if left < heap_size and lst[left] > lst[largest]:
                largest = left 
            if right < heap_size and lst[right] > lst[largest]:
                largest = right
            if largest != index:  # if there were swaps then, swap index and largest and iterature to next level in heap 
                lst[index], lst[largest] = lst[largest], lst[index] # swaps either
                max_heapify(heap_size, largest)
        for i in range(len(lst)// 2 - 1, -1, -1): # this heapifies the binary tree 
            max_heapify(heap_size, i) 
        for i in range(len(lst) -1, 0, -1):
            lst[i], lst[0] = lst[0], lst[i]
            max_heapify(i, 0) # cuz the size is reducing one by one and the starting index is 0...to 
