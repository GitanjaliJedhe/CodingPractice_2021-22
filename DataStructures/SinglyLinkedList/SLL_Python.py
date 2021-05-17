# Singly Linked List in Python 

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None;

class SinglyLinkedList:
    def __init__(self):
        self.head = None;

    def printLL(self):
        temp = self.head;
        output = " "
        while (temp != None):
            output = output+(str(temp.data)+" -> ")
            temp = temp.next
        print (output + " NULL\n");

# Code execution starts here
if __name__ == '__main__':
    sll = SinglyLinkedList()
    
    sll.head = Node(100);
    second = Node(200);
    third = Node(300);
    
    sll.head.next = second;
    second.next = third;
    third.next = None;
    
    sll.printLL();
    
"""
Output:
 100 -> 200 -> 300 ->  NULL
"""