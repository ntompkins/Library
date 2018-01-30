/*
  Name: Nathan Tompkins
  Project: CSII, Assignment 08
  Completed: 11.20.2017
  Time Spent: 2 hours
  OS: Ubuntu Linux
  Description: This program draws a smiley face using JavaFX shapes.
*/

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.StrokeType;
import javafx.scene.control.ContentDisplay;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.layout.AnchorPane;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.QuadCurve;

public class Assignment08 extends Application {
@Override
public void start(Stage primaryStage) {
        // Create Head
        Circle head = new Circle(145.0,172.0,100.0);
        head.setFill(Color.LIGHTGOLDENRODYELLOW);
        head.setStroke(Color.WHITE);
        head.setStrokeWidth(0.0);
        // Create Eyes
        Circle leftWhite = new Circle(100.0,150.0,20.0);
        leftWhite.setFill(Color.WHITE);
        leftWhite.setStroke(Color.BLACK);

        Circle rightWhite = new Circle(188.0,152.0,20.0);
        rightWhite.setFill(Color.WHITE);
        rightWhite.setStroke(Color.BLACK);

        Circle leftPupil = new Circle(109.0,151.0,13.0);
        leftPupil.setFill(Color.BLACK);

        Circle rightPupil = new Circle(179.0,152.0,13.0);
        rightPupil.setFill(Color.BLACK);

        // Create Smile
        QuadCurve smile = new QuadCurve();
        smile.setStartX(-50.0);
        smile.setEndX(50.0);
        smile.setControlX(-50.0);
        smile.setControlY(-100.0);
        smile.setLayoutX(140.0);
        smile.setLayoutY(245.0);
        smile.setRotate(180.0);
        smile.setFill(Color.WHITE);
        smile.setStroke(Color.BLACK);

        // Create Nose
        Polygon nose = new Polygon();
        nose.getPoints().addAll(new Double[]{
          -50.0, 40.0, 50.0, 40.0, 0.0, -60.0
        });
        nose.setLayoutX(143.0);
        nose.setLayoutY(168.0);
        nose.setScaleX(0.25);
        nose.setScaleY(0.5);
        nose.setStroke(Color.BLACK);
        nose.setStrokeWidth(0.0);
        nose.setFill(Color.GOLDENROD);

        // Create anchorpane to hold everything
        AnchorPane anchorpane = new AnchorPane();
        anchorpane.setPrefHeight(344.0);
        anchorpane.setPrefWidth(316.0);
        anchorpane.setMaxHeight(-1.0);
        anchorpane.setMaxWidth(-1.0);
        anchorpane.getChildren().addAll(head,leftWhite,rightWhite,leftPupil,rightPupil,smile,nose);

        // Place everything inside the scene
        Scene scene = new Scene(anchorpane, 300, 300);
        primaryStage.setTitle("A Smiley Face For Rouse");
        primaryStage.setScene(scene);
        primaryStage.show();

}
}
