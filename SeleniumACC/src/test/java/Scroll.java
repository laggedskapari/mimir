import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.safari.SafariDriver;

public class Scroll {
  public static void main(String[] args) {
    WebDriver driver = new SafariDriver();

    driver.navigate().to("https://formy-project.herokuapp.com/scroll");

    WebElement name = driver.findElement(By.id("name"));

    Actions action = new Actions(driver);
    action.moveToElement(name);
    name.sendKeys("Meagan Lewis");

    WebElement date = driver.findElement(By.id("date"));
    date.sendKeys("01/01/2020");

    driver.quit();
  }
}
