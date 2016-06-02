# Sudoku Solver
# prompt: http://programmingpraxis.com/2009/02/19/sudoku/

# Nine numbers in nine squares

# Var to represent empty space
nn = None

board = {   1:7,
            2:nn,
            3:nn,
            4:nn,
            5:2,
            6:nn,
            7:nn,
            8:nn,
            9:nn,   # Box 1
            10:1,
            11:nn,
            12:nn,
            13:nn,
            14:nn,
            15:nn,
            16:nn,
            17:nn,
            18:6,   # Box 2
            19:nn,
            20:nn,
            21:nn,
            22:nn,
            23:1,
            24:5,
            25:3,
            26:9,
            27:nn,  # Box 3
            28:2,
            29:nn,
            30:nn,
            31:nn,
            32:4,
            33:nn,
            34:nn,
            35:nn,
            36:nn,  # Box 4
            37:nn,
            38:1,
            39:8,
            40:nn,
            41:9,
            42:nn,
            43:7,
            44:5,
            45:nn,  # Box 5
            46:nn,
            47:nn,
            48:nn,
            49:nn,
            50:7,
            51:nn,
            52:nn,
            53:nn,
            54:3,   # Box 6
            55:nn,
            56:7,
            57:8,
            58:5,
            59:6,
            60:nn,
            61:nn,
            62:nn,
            63:nn,  # Box 7
            64:5,
            65:nn,
            66:nn,
            67:nn,
            68:nn,
            69:nn,
            70:nn,
            71:nn,
            72:1,   # Box 8
            73:nn,
            74:nn,
            75:nn,
            76:nn,
            77:4,
            78:nn,
            79:nn,
            80:nn,
            81:2    # Box 9
            }
for x in board:
    print(x,board[x])
