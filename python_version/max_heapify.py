class Heapify(object):
    def __init__(self, data = None):
        self.data = data or []
        for i in range(len(data)//2, -1, -1):
            self.__max_heapify__(i)
            
    def __repr__(self):
        return repr(self.data)
    
    def parent(self, i):
        if i & 1:
            return i >> 1
        else:
            return (i >> 1) -1
        
    def left_child(self, i):
        return (i << 1) + 1
    
    
    def right_child(self, i):
        return (i << 1) + 2
    
    def __max_heapify__(self, i):
        largest = i # 현재 노드
        left = self.left_child(i)
        right = self.right_child(i)
        n = len(self.data)
        
        # left_child
        largest = (left < n and self.data[left] > self.data[i] and left or i)
        
        # right_child
        largest = (right < n and self.data[right] > self.data[largest] and right or largest)
        
        if i is not largest:
            self.data[i], self.data[largest] = self.data[largest], self.data[i]
            self.__max_heapify__(largest)
            
    def extract_max(self):
        n = len(self.data)
        max_element = self.data[0] 
        
        #첫번째 노드에 마지막 노드 대입 
        self.data[0] = self.data[n-1]
        self.data = self.data[ : n-1]
        self.__max_heapify__(0)
        
        return max_element
    
    def insert(self, item):
        i = len(self.data)
        self.data.append(item)
        while(i != 0) and item > self.data[self.parent(i)]:
            #print(self.data)
            self.data[i] = self.data[self.parent(i)]
            i = self.parent(i) 
        self.data[i] = item
        
        
lst = [3, 2, 5, 1, 7, 8, 2]     
print("처음 상태 ", lst)
h = Heapify(lst)
print("max_heapify ", h)
print("8 삭제 ", end='')
h.extract_max() == 8
print(h)
print("10 추가 ", end='')
h.insert(10)
print(h)

'''
실행결과

처음 상태  [3, 2, 5, 1, 7, 8, 2]
max_heapify  [8, 7, 5, 1, 2, 3, 2]
8 삭제 [7, 2, 5, 1, 2, 3]
10 추가 [10, 2, 7, 1, 2, 3, 5]

'''


