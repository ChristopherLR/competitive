struct Solution;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

impl ListNode {
    pub fn push(self, elem: i32) -> ListNode {
        ListNode {
            val: elem,
            next: Some(Box::new(self)),
        }
    }

    pub fn to_vec(self) -> Vec<i32> {
        let mut vec = Vec::new();
        vec.push(self.val);

        let mut tmp = self.next;

        while tmp != None {
            let ( tmp_val, tmp_next ) = match *tmp.take().unwrap() {
                ListNode { val, next } => (val, next)
            };
            vec.push(tmp_val);
            tmp = tmp_next;
        }

        vec
    }
}

impl Solution {
    // Runtime 58ms, Memory 6.2MB
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        if head == None {
            return false;
        }

        let vec = head.unwrap().to_vec();

        for i in 0..vec.len() {
            if vec[i] != vec[vec.len() - 1 - i] { return false };
        }

        true
    }
}

fn main() {
    let ln = ListNode::new(1).push(2).push(2).push(1);
    println!("{:?}", Solution::is_palindrome(Some(Box::new(ln))));
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn _1() {
        let head = Some(Box::new(ListNode::new(1)));
        assert_eq!(Solution::is_palindrome(head), true);
    }

    #[test]
    fn _12() {
        let head = ListNode::new(2).push(1);
        assert_eq!(Solution::is_palindrome(Some(Box::new(head))), false);
    }

    #[test]
    fn _1221() {
        let head = ListNode::new(1).push(2).push(2).push(1);
        assert_eq!(Solution::is_palindrome(Some(Box::new(head))), true);
    }

    #[test]
    fn _12121() {
        let head = ListNode::new(1).push(2).push(1).push(2).push(1);
        assert_eq!(Solution::is_palindrome(Some(Box::new(head))), true);
    }
}
