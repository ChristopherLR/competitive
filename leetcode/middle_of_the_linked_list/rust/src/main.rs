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
}

impl Solution {
    // Runtime 1ms, Memory 2MB
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head == None {
            return None;
        }

        let head_next = head.to_owned().unwrap().next;
        if head_next == None {
            return head;
        }

        let mut slow = head_next.to_owned();
        let mut fast = slow.clone().unwrap().next;

        while let Some(mut n) = fast.take() {
            if n.next != None {
                slow = slow.take().unwrap().next;
                fast = n.next.take().unwrap().next;
            } else {
                return slow
            }
        }
        return slow
    }
}

fn main() {
    let ln = ListNode::new(4).push(3).push(2).push(1);
    println!("{:?}", Solution::middle_node(Some(Box::new(ln))));
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn _1() {
        let head = ListNode::new(4).push(3).push(2).push(1);
        let middle = ListNode::new(4).push(3);
        assert_eq!(
            Solution::middle_node(Some(Box::new(head))),
            Some(Box::new(middle))
        );
    }

    #[test]
    fn _2() {
        let head = ListNode::new(5).push(4).push(3).push(2).push(1);
        let middle = ListNode::new(5).push(4).push(3);
        assert_eq!(
            Solution::middle_node(Some(Box::new(head))),
            Some(Box::new(middle))
        );
    }
}
