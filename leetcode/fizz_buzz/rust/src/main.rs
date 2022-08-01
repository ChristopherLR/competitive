struct Solution;

impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        (1..=n)
            .map(|num| {
                if num % 15 == 0 {
                    "FizzBuzz".to_owned()
                } else if num % 3 == 0 {
                    "Fizz".to_owned()
                } else if num % 5 == 0 {
                    "Buzz".to_owned()
                } else {
                    num.to_string()
                }
            })
            .collect()
    }
}

fn main() {}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn _1() {
        assert_eq!(Solution::fizz_buzz(3), vec!["1", "2", "Fizz"]);
    }

    #[test]
    fn _2() {
        assert_eq!(Solution::fizz_buzz(5), vec!["1", "2", "Fizz", "4", "Buzz"]);
    }
}
