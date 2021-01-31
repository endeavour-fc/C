#两数之和
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    hashtable=dict()
    for i,num in enumerate(nums):
        if(target-num in hashtable):
            return [i,hashtable[target-num]]
        hashtable[nums[i]]=i
    return []

nums=[2,7,11,15]
#target=9
#print(twoSum(nums,target))

print(list(enumerate(nums)))

#反转链表
def reverseList(self, head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    if(head == None or head.next == None):
        return head
    pPre=head
    pCur=head.next
    temp=None
    while(1):
        pPre.next=temp
        temp=pPre
        pPre=pCur
        if(pPre == None):
            return temp
        pCur=pCur.next
    return None

#有效的括号
def isValid(self, s):
    """
    :type s: str
    :rtype: bool
    """
    if(len(s)%2):
        return False

    pair={")":"(","]":"[","}":"{"}
    stack=list()
    for c in s:
        if(c in pair):
            if( not stack or stack[-1]!=pair[c] ):
                return False
            stack.pop()
        else:
            stack.append(c)
    return not stack