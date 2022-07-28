struct Solution;

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut vec = vec![0;26];
        for c in magazine.as_bytes() {
            vec[(c - b'a') as usize] += 1;
        }
        for c in ransom_note.as_bytes() {
            let idx = (c - b'a') as usize;
            if vec[idx] == 0 {
                return false
            } else {
                vec[idx] -= 1;
            }
        }
        true
    }
}

fn main() {}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn _1() {
        assert_eq!(
            Solution::can_construct("a".to_string(), "b".to_string()),
            false
        );
    }

    #[test]
    fn _2() {
        assert_eq!(
            Solution::can_construct("aa".to_string(), "ab".to_string()),
            false
        );
    }

    #[test]
    fn _3() {
        assert_eq!(
            Solution::can_construct("aa".to_string(), "aab".to_string()),
            true
        );
    }

    #[test]
    fn _4() {
        let a ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa".to_string();

        let b ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa".to_string();
        assert_eq!(
            Solution::can_construct(a, b),
            true
        );
    }
}
