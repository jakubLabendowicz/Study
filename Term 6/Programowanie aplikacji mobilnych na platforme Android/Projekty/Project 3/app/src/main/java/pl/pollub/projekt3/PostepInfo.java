package pl.pollub.projekt3;

import android.os.Parcel;
import android.os.Parcelable;

public class PostepInfo implements Parcelable
{
    public int mPobranychBajtow;
    public int mRozmiar;
    public int mStatus;


    public PostepInfo()
    {
      mPobranychBajtow = 0;
      mRozmiar = 0;
      mStatus = 0;
    }

    //obowiązkowy konstruktor tworzy obiekt na podstawie paczki
    public PostepInfo(Parcel paczka)
    {
        //ważna kolejność
        // 1, 2, 3, ...
        mPobranychBajtow = paczka.readInt();
        mRozmiar = paczka.readInt();
        mStatus = paczka.readInt();
    }

    @Override
    public int describeContents()
    {
        return 0;
    }

    //zapisuje do obiekt do paczki
    @Override
    public void writeToParcel(Parcel dest, int flags)
    {
        // ważna kolejność
        // 1, 2, 3, ...
        dest.writeInt(mPobranychBajtow);
        dest.writeInt(mRozmiar);
        dest.writeInt(mStatus);
    }

    //trzeba utworzyć obiekt CREATOR
    public static final Creator<PostepInfo> CREATOR = new Creator<PostepInfo>()
    {
        @Override
        public PostepInfo createFromParcel(Parcel source)
        {
            return new PostepInfo(source);
        }

        @Override
        public PostepInfo[] newArray(int size)
        {
            return new PostepInfo[size];
        }
    };
}
