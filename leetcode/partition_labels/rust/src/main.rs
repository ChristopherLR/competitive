struct Solution;

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let mut max_indices = vec![0;26];
        for (idx , c ) in s.bytes().enumerate() {
            max_indices[(c - b'a') as usize] = idx as i32;
        }

        let mut max: i32= 0;
        let mut last_idx: i32 = -1;

        let mut partitions = Vec::new();

        for (idx, c) in s.bytes().enumerate() {
            max = std::cmp::max(max, max_indices[(c - b'a') as usize]);
            if max == idx as i32 {
                partitions.push(max - last_idx);
                last_idx = max;
            }
        }

        partitions
    }
}

fn main() {
    assert_eq!(Solution::partition_labels("ababcbacadefegdehijhklij".to_owned()), vec![9, 7, 8]);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn _1() {
        assert_eq!(Solution::partition_labels("ababcbacadefegdehijhklij".to_owned()), vec![9, 7, 8]);
    }

    #[test]
    fn _2() {
        assert_eq!(Solution::partition_labels("eccbbbbdec".to_owned()), vec![10]);
    }

    #[test]
    fn _3() {
        assert_eq!(Solution::partition_labels("bceacbacdbbadea".to_owned()), vec![15]);
    }

}
