import org.openqa.selenium.Alert;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.safari.SafariDriver;

public class SwitchToAlert {
  public static void main(String[] args) {
    WebDriver driver = new SafariDriver();

    driver.navigate().to("https://formy-project.herokuapp.com/switch-window");

    WebElement alertButton = driver.findElement(By.id("alert-button"));
    alertButton.click();

    Alert alert = driver.switchTo().alert();
    alert.accept();

    driver.quit();
  }
}
