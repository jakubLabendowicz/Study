using Lab2___Owocki;

namespace Lab2___Tests
{
    public class UnitTest1
    {
        [Fact]
        public void
            FormatUsdPrice_ProperFormat_ShouldReturnProperString()
        {
            var data = 0.05;
            var result = MyFormatter.FormatUsdPrice(data);
            Assert.Matches(@"\$\d{1,3}(?:[.,]\d{3})*(?:[.,]\d{2})", result);
        }
    }
}