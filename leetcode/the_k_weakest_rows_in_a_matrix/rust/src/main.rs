struct Solution;

impl Solution {
    // Runtime 0ms, Memory 2.1MB
    pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut results: Vec<(i32, i32)> = Vec::new();

        for (idx, col) in mat.iter().enumerate() {
            results.push((col.iter().sum(), idx as i32));
        }

        results.sort();
        results[0..(k as usize)].iter().map(|a| a.1).collect()
    }
}

fn main() {
    let mat: Vec<Vec<i32>> = vec![
        vec![1, 1, 0, 0, 0],
        vec![1, 1, 1, 1, 0],
        vec![1, 0, 0, 0, 0],
        vec![1, 1, 0, 0, 0],
        vec![1, 1, 1, 1, 1],
    ];

    assert_eq!(Solution::k_weakest_rows(mat, 3), vec![2, 0, 3]);
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn _1() {
        let mat: Vec<Vec<i32>> = vec![
            vec![1, 1, 0, 0, 0],
            vec![1, 1, 1, 1, 0],
            vec![1, 0, 0, 0, 0],
            vec![1, 1, 0, 0, 0],
            vec![1, 1, 1, 1, 1],
        ];

        assert_eq!(Solution::k_weakest_rows(mat, 3), vec![2, 0, 3]);
    }

    #[test]
    fn _2() {
        let mat: Vec<Vec<i32>> = vec![
            vec![1, 0, 0, 0],
            vec![1, 1, 1, 1],
            vec![1, 0, 0, 0],
            vec![1, 0, 0, 0],
        ];

        assert_eq!(Solution::k_weakest_rows(mat, 2), vec![0, 2]);
    }
}
