public interface FlightOperations {
    private double angle;
    private double direction;

    public double getAngle();
    public void setAngle(double angle);
    public double getDirection();
    public void setDirection(double direction);
}

public class TurnRight implements FlightOperations {

  private double angle;
  private double direction;

  public double getAngle() {
    return angle;
  }

  public void setAngle(double angle) {
    this.angle = angle;
  }

  public double getDirection() {
    return direction;
  }

  public void setDirection(double direction) {
    this.direction = direction;
  }
}

public class TurnLeft implements FlightOperations {

  private double angle;
  private double direction;

  public double getAngle() {
    return angle;
  }

  public void setAngle(double angle) {
    this.angle = angle;
  }

  public double getDirection() {
    return direction;
  }

  public void setDirection(double direction) {
    this.direction = direction;
  }
}

public class Plane {

  public void fly(FlightOperations operation) {
    if (operation == null) {
      throw new InvalidParameterException("Can not perform operation");
    }
    if (operation instanceof TurnRight) {
      TurnRight turnRight = (TurnRight) operation;
      turnRight.setDirection(turnRight.getDirection + turnRight.getAngle());
    } else if (operation instanceof TurnLeft) {
      TurnLeft turnLeft = (TurnLeft) operation;
      turnLeft.setDirection(turnLeft.getDirection - turnLeft.getAngle());
    }
  }
}
