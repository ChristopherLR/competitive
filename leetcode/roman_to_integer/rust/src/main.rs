struct Solution;



impl Solution {
    pub fn to_i(c: char) -> i32 {
        match c {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0
        }
    }

    pub fn roman_to_int(s: String) -> i32 {
        let len = s.len();

        match len {
            0 => { 0 }
            1 => { return Solution::to_i(s.chars().nth(0).unwrap()) },
            _ => {
                let mut sum = 0;
                let mut i = 0;
                loop {
                    let first = Solution::to_i(s.chars().nth(i).unwrap());
                    let second = Solution::to_i(s.chars().nth(i + 1).unwrap());

                    if first < second {
                        sum += second - first;
                        i += 1;
                        if i == len - 2 {
                            sum += Solution::to_i(s.chars().nth(i + 1).unwrap());
                        }
                    } else {
                        sum += first;
                        if i == len - 2 {
                            sum += second;
                        }
                    }

                    i += 1;
                    if i >= len - 1 { 
                        break
                    }
                }
                sum
            }
        }
    }
}

// 4ms, 1.9MB

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn _1(){ assert_eq!(1, Solution::roman_to_int("I".to_string())); }
    #[test]
    fn _4(){ assert_eq!(4, Solution::roman_to_int("IV".to_string())); }
    #[test]
    fn _58(){ assert_eq!(58, Solution::roman_to_int("LVIII".to_string())); }
    #[test]
    fn _1994(){ assert_eq!(1994, Solution::roman_to_int("MCMXCIV".to_string())); }
    #[test]
    fn _1695(){ assert_eq!(1695, Solution::roman_to_int("MDCXCV".to_string())); }
}

fn main() {
    println!("1994 {}", Solution::roman_to_int("MCMXCIV".to_string()));
    println!("1695 {}", Solution::roman_to_int("MDCXCV".to_string()));
}
