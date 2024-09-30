import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.By;
import org.openqa.selenium.safari.SafariDriver;

public class Main {
  public static void main(String[] args) {

    WebDriver driver = new SafariDriver();

    driver.navigate().to("https://formy-project.herokuapp.com/keypress");

    WebElement name = driver.findElement(By.id("name"));
    name.click();
    name.sendKeys("Rajat Sharma");

    WebElement button = driver.findElement(By.id("button"));
    button.click();

    driver.quit();
  }
}
