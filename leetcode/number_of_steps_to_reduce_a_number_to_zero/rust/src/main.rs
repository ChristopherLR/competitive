struct Solution;

impl Solution {
    pub fn number_of_steps(num: i32) -> i32 {
        let mut ans = 0;
        let mut n = num;
        while n != 0 {
            if n % 2 == 0 {
                n /= 2;
            } else {
                n -= 1;
            }
            ans += 1;
        }
        ans
    }
}

fn main() {
    assert_eq!(Solution::number_of_steps(14), 6);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn _1() {
        assert_eq!(Solution::number_of_steps(14), 6);
    }

    #[test]
    fn _2() {
        assert_eq!(Solution::number_of_steps(8), 4);
    }

    #[test]
    fn _3() {
        assert_eq!(Solution::number_of_steps(123), 12);
    }

    #[test]
    fn _4() {
        assert_eq!(Solution::number_of_steps(4), 3);
    }
}
