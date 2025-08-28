
class Solution {
    private void Aorder(int[][] grid, int col) {
        int row = 0;
        ArrayList<Integer> arr = new ArrayList<>();

        for (int i = col; i < grid.length; i++) {
            arr.add(grid[row][i]);
            row++;
        }

        Collections.sort(arr);

        row = 0;
        int idx = 0;
        for (int i = col; i < grid.length; i++) {
            grid[row][i] = arr.get(idx++);
            row++;
        }
    }

    private void Dorder(int[][] grid, int row) {
        int col = 0;
        ArrayList<Integer> arr = new ArrayList<>();

        for (int i = row; i < grid.length; i++) {
            arr.add(grid[i][col]);
            col++;
        }

        Collections.sort(arr, Collections.reverseOrder());

        col = 0;
        int idx = 0;
        for (int i = row; i < grid.length; i++) {
            grid[i][col] = arr.get(idx++);
            col++;
        }
    }

    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;

        for (int col = 1; col < n; col++) {
            Aorder(grid, col);
        }

        for (int row = 0; row < n; row++) {
            Dorder(grid, row);
        }

        return grid;
    }
}
