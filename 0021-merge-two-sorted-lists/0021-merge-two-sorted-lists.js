/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {

    let dummy =new ListNode(-1);
    let current =dummy;

        while(list1 !=null || list2 !=null){
            if(list1 ==null){

                let a=list2.val;
              current.next=new ListNode(a);
              current=current.next;
              list2=list2.next;
            }else if(list2 ==null){
                 let a=list1.val;
              current.next=new ListNode(a);
                  current=current.next;
              list1=list1.next;

            }else if(list1.val <=list2.val){
                let a=list1.val;
                 current.next=new ListNode(a);
                current=current.next;
                list1=list1.next;
            }else{
                 let a=list2.val;
                 current.next=new ListNode(a);
                 current=current.next;
                list2=list2.next;
            }
        
    }

return dummy.next;

};