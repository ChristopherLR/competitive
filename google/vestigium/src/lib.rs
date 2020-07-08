#[cfg(test)]
mod tests {

    #[test]
    fn s1() {
        let matrix = vec![
            vec![1, 2, 3, 4],
            vec![2, 1, 4, 3],
            vec![3, 4, 1, 2],
            vec![4, 3, 2, 1],
        ];
        assert_eq!(trace(4, &matrix), (4, 0, 0));
    }
}
