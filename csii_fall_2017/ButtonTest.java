import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;

public class ButtonTest extends Application {
   @Override
   public void start(Stage primaryStage) {
      Button myButton = new Button("Hello World");
      myButton.setStyle("-fx-font: 100 Calibri;-fx-text-fill: #ffffff; -fx-backgrond-image: url('background.jpg');");
      
      Scene myScene = new Scene(myButton,200,250);
      primaryStage.setTitle("First GUI");
      primaryStage.setScene(myScene);
      primaryStage.show();
      
      Stage nextStage = new Stage();
      nextStage.setTitle("Second Scene");
      Button nextButton = new Button("Bye World!");
      Scene nextScene = new Scene(nextButton, 300, 300);
      nextStage.setScene(nextScene);
      nextStage.show();
   }
}
// !! pp.552-559 (JavaFX Layout Panes)
// !! Event-Driven Programming Animation (Chapter 15)