import java.util.Scanner;

public class TicTacToe {

    //Enumeration for game status
    public enum GameStatus{
        WIN, DRAW, CONTINUE
    }

    private char[][]board; //3x3 board
    private char currentPlayer; //X or O 

    public TicTacToe(){
        board = new char[3][3];
        currentPlayer = 'X'; 
        initializeBoard();
    }

    //Initialize board with empty spaces
    private void initializeBoard(){
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] =' ';
            }
        }
    }

    //Print the board
    public void printBoard(){
        System.out.println(" _______________________");
        for (int i =0; i < 3; i++){
            System.out.println("|       |       |       |");
            System.out.printf("|   %c   |   %c   |   %c   |\n",
                    board[i][0], board[i][1], board[i][2]);
            System.out.println("|_______|_______|_______|");
        }
    }

    //Make a move
    public boolean makeMove (int row, int col){
        if(row < 0 || row > 2 || col < 0 || col > 2){
            System.out.println("Invalid position. Try again.");
            return false;
        }

        if (board[row][col] != ' '){
            System.out.println("Square already occupied. Try again.");
            return false;
        }

        board[row][col] = currentPlayer; 
        return true;
    }

    //Check game status
    public GameStatus checkGameStatus(){
        if(checkWIN()){
            return GameStatus.WIN;
        }

        if(isBoardFull()){
            return GameStatus.DRAW;
        }

        return GameStatus.CONTINUE;
    }

    //Check for win
    private boolean checkWIN(){
        //Rows & columns
        for(int i = 0; i < 3; i++){
            if(board[i][0] == currentPlayer &&
                board[i][1] == currentPlayer &&
                board[i][2] == currentPlayer) {
                    return true;
        }
            
        if (board[0][i] == currentPlayer&&
            board[1][i] == currentPlayer&&
            board[2][i] == currentPlayer){
                return true;
            }
        }

        //Diagonals
        if (board[0][0] == currentPlayer &&
            board[1][1] == currentPlayer &&
            board[2][2] == currentPlayer){
                return true;
            }

            if(board[0][2] == currentPlayer &&
                board[1][1] == currentPlayer &&
                board[2][2] == currentPlayer){
                    return true;
                }
            
                return false;
    }

    //Check if board is full
    private boolean isBoardFull(){
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[i][j] == ' '){
                    return false;
                }
            }
        }
    return true;
    }

//Switch Player 
private void switchPlayer(){
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

//Main game loop
public void play(){
    Scanner scanner = new Scanner(System.in);
    GameStatus status = GameStatus.CONTINUE;

    while (status == GameStatus.CONTINUE){
        printBoard();
        System.out.println("Player " + currentPlayer + "'s tun.");

        System.out.print("Enter row (0, 1 or 2): ");
        int row = scanner.nextInt();
        System.out.print("Enter column (o, 1 or 2): ");
        int col = scanner.nextInt();

        if (makeMove(row, col)){
            status = checkGameStatus();
            if (status == GameStatus.CONTINUE){
                switchPlayer();
            }
        }
    }

    printBoard(); 
    if (status == GameStatus.WIN){
        System.out.println("Player " + currentPlayer +" wins.");
    }else{
        System.out.println("The game is a draw");
    }
    scanner.close();
}

public static void main(String[] args){
    TicTacToe game = new TicTacToe(); 
    game.play();
}
}
