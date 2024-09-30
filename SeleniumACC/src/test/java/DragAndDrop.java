import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.safari.SafariDriver;

public class DragAndDrop {
  public static void main(String[] args) throws InterruptedException {
    WebDriver driver = new SafariDriver();

    driver.navigate().to("https://formy-project.herokuapp.com/dragdrop");
    Thread.sleep(5000);

    WebElement image = driver.findElement(By.id("image"));

    WebElement box = driver.findElement(By.id("box"));

    Actions actions = new Actions(driver);

    actions.dragAndDrop(image, box).build().perform();

    driver.quit();
  }
}
