struct Solution;

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts.iter().map(|acc| acc.iter().sum()).max().unwrap()
    }
}

pub fn main() {
    println!(
        "{}",
        Solution::maximum_wealth(vec![vec![1, 2, 3], vec![2, 3, 4]])
    );
}
