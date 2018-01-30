import javafx.application.Application;
import java.util.Scanner;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.SplitPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.Tooltip;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.RowConstraints;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import javafx.scene.Scene;

public class Assignment09 extends Application {
@Override
public void start(Stage primaryStage) {

        // Create Objects
        Scanner input = new Scanner(System.in);
        Calculator calculator = new Calculator();
        // Create buttons
        Button button_clear = new Button("C");
        Button button_delete = new Button("<-");
        Button button_enter = new Button("=");
        Button button_sub = new Button("-");
        Button button_add = new Button("+");
        Button button_mul = new Button("*");
        Button button_div = new Button("/");
        Button button_pow = new Button("^");
        Button button_9 = new Button("9");
        Button button_8 = new Button("8");
        Button button_7 = new Button("7");
        Button button_6 = new Button("6");
        Button button_5 = new Button("5");
        Button button_4 = new Button("4");
        Button button_3 = new Button("3");
        Button button_2 = new Button("2");
        Button button_1 = new Button("1");
        Button button_0 = new Button("0");
        Button button_dec = new Button(".");
      // Style All buttons
       // Red action buttons
        button_clear.getStyleClass().add("red-btn");
        button_delete.getStyleClass().add("red-btn");
        button_enter.getStyleClass().add("red-btn");
        // Green operation buttons
        button_sub.getStyleClass().add("green-btn");
        button_add.getStyleClass().add("green-btn");
        button_mul.getStyleClass().add("green-btn");
        button_div.getStyleClass().add("green-btn");
        button_pow.getStyleClass().add("green-btn");
        // Blue digit buttons
        button_9.getStyleClass().add("blue-btn");
        button_8.getStyleClass().add("blue-btn");
        button_7.getStyleClass().add("blue-btn");
        button_6.getStyleClass().add("blue-btn");
        button_5.getStyleClass().add("blue-btn");
        button_4.getStyleClass().add("blue-btn");
        button_3.getStyleClass().add("blue-btn");
        button_2.getStyleClass().add("blue-btn");
        button_1.getStyleClass().add("blue-btn");
        button_0.getStyleClass().add("blue-btn");
        button_dec.getStyleClass().add("blue-btn");
        // Create rows to hold the buttons
        ButtonBar row1 = new ButtonBar();
        ButtonBar row2 = new ButtonBar();
        ButtonBar row3 = new ButtonBar();
        ButtonBar row4 = new ButtonBar();
        ButtonBar row5 = new ButtonBar();
        // Set button data
        // ButtonBar.setButtonData(button_clear); //, ButtonData.CLEAR);
        // ButtonBar.setButtonData(button_delete); //, ButtonData.DELETE);
        // ButtonBar.setButtonData(button_pow); //, ButtonData.POW);
        // ButtonBar.setButtonData(button_mul); //, ButtonData.MUL);
        // ButtonBar.setButtonData(button_div); //, ButtonData.DIV);
        // ButtonBar.setButtonData(button_add); //, ButtonData.ADD);
        // ButtonBar.setButtonData(button_sub); //, ButtonData.SUB);
        // ButtonBar.setButtonData(button_9); //, ButtonData.NINE);
        // ButtonBar.setButtonData(button_8); //, ButtonData.EIGHT);
        // ButtonBar.setButtonData(button_7); //, ButtonData.SEVEN);
        // ButtonBar.setButtonData(button_6); //, ButtonData.SIX);
        // ButtonBar.setButtonData(button_5); //, ButtonData.FIVE);
        // ButtonBar.setButtonData(button_4); //, ButtonData.FOUR);
        // ButtonBar.setButtonData(button_3); //, ButtonData.THREE);
        // ButtonBar.setButtonData(button_2); //, ButtonData.TWO);
        // ButtonBar.setButtonData(button_1); //, ButtonData.ONE);
        // ButtonBar.setButtonData(button_0); //, ButtonData.ZERO);
        // ButtonBar.setButtonData(button_dec); //, ButtonData.DEC);
        // Add buttons to rows
        row1.getButtons().addAll(button_clear,button_delete,button_pow,button_mul);
        row2.getButtons().addAll(button_7,button_8,button_9,button_div);
        row3.getButtons().addAll(button_4,button_5,button_6,button_sub);
        row4.getButtons().addAll(button_1,button_2,button_3,button_add);
        row5.getButtons().addAll(button_0,button_dec,button_enter);
        // Create master box
        VBox mainBox = new VBox();
        // Creat SplitPane for text on top and buttons on bottom
        SplitPane splitPane = new SplitPane();
        ScrollPane output = new ScrollPane();
        // Create pane to hold button rows
        GridPane keyboard = new GridPane();
        GridPane.setConstraints(row1, 1, 0);
        GridPane.setConstraints(row2, 2, 0);
        GridPane.setConstraints(row3, 3, 0);
        GridPane.setConstraints(row4, 4, 0);
        GridPane.setConstraints(row5, 5, 0);
        // Add rows to keyboard
        keyboard.getChildren().addAll(row1,row2,row3,row4,row5);
        // Add output and keyboard to splitpane
        splitPane.getItems().addAll(output,keyboard);
        // Add splitpane to main vbox
        mainBox.getChildren().addAll(splitPane); // Add all components
        // Add vbox to scene
        Scene scene = new Scene(mainBox,1000,1000); //,400.0,550.0); // Create scene to hold main components
        // Apply style sheet
        scene.getStylesheets().add("calcStyle.css"); // Add CSS Sheet
        // Title the application
        primaryStage.setTitle("Calculator");
        // Set the scene on the stage
        primaryStage.setScene(scene);
        // Run the program
        primaryStage.show();

        // Close Scanner
        input.close();
        // case '+': symbol = '+'; break;
        // case '-': symbol = '-'; break;
        // case '*': symbol = 'ร—'; break;
        // case '/': symbol = 'รท'; break;
}
}
