impl Solution {
    // Runtime 110ms, Memory 13 MB
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        if head == None {
            return false;
        }

        let ( next, val ) = match *head.clone().unwrap() {
            ListNode { next, val } => (next, val),
        };

        if next == None {
            return true;
        }

        let mut length = 1;
        let mut tmp = next;
        let mut tail = Some(Box::new(ListNode::new(val)));
        let mut new_head ;

        while tmp != None {
            length += 1;
            let ( tmp_val, tmp_next ) = match *tmp.take().unwrap() {
                ListNode { val, next } => (val, next)
            };

            new_head = Some(Box::new(ListNode { val: tmp_val, next: tail.take() }));
            tail = new_head;
            tmp = tmp_next;
        }

        let mut new_head = head;
        for _ in 0..length/2 {
            let ( head_val, head_next ) = match *new_head.take().unwrap() {
                ListNode { val, next } => (val, next)
            };

            let ( tail_val, tail_next ) = match *tail.take().unwrap() {
                ListNode { val, next } => (val, next)
            };

            if head_val != tail_val { return false; }

            new_head = head_next;
            tail = tail_next;
        }

        true
    }
}