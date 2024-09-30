import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.safari.SafariDriver;

public class AutoComplete {
  public static void main(String[] args) throws InterruptedException {

    WebDriver driver = new SafariDriver();
    driver.navigate().to("https://formy-project.herokuapp.com/autocomplete");

    WebElement autoComplete = driver.findElement(By.id("autocomplete"));
    autoComplete.sendKeys("1555 Park Blvd, Palo Alto, CA");

    Thread.sleep(10000);
    
    WebElement autoCompleteResult = driver.findElement(By.className("pac-item"));
    autoCompleteResult.click();

    driver.quit();
  }
}
