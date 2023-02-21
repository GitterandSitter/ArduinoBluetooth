package com.example.bluetoothmap;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.FragmentActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.example.bluetoothmap.databinding.ActivityMapsBinding;

public class MapsActivity extends FragmentActivity implements GoogleMap.OnMarkerClickListener, GoogleMap.OnMarkerDragListener,
        GoogleMap.OnInfoWindowClickListener, GoogleMap.InfoWindowAdapter
        , OnMapReadyCallback {

    private GoogleMap mMap;
    private ActivityMapsBinding binding;

    private final LatLng KOS = new LatLng(36.895, 27.28111);


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMapsBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
    }


    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        // Add a marker on Kos and move the camera

        mMap.addMarker(new MarkerOptions().position(KOS).draggable(true).title("Click marker to send coordinates"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(KOS));

        mMap.setInfoWindowAdapter(this);
        mMap.setOnMarkerDragListener(this);
        mMap.setOnInfoWindowClickListener(this);
    }

    @Override
    public void onInfoWindowClick(@NonNull Marker marker) {
        LatLng markerPosition = marker.getPosition();
        Toast.makeText(this, "Coordinates sent",
                Toast.LENGTH_SHORT).show();
        Intent intent = new Intent(MapsActivity.this, MainActivity.class);
        intent.putExtra("position", markerPosition.toString().substring(10, 45));
        MapsActivity.this.startActivity(intent);

    }

    @Override
    public boolean onMarkerClick(@NonNull Marker marker) {
        return false;
    }

    @Override
    public void onMarkerDrag(@NonNull Marker marker) {

    }

    @Override
    public void onMarkerDragEnd(@NonNull Marker marker) {
        LatLng markerPosition = marker.getPosition();
        marker.setSnippet(String.valueOf(markerPosition));
        marker.showInfoWindow();
    }

    @Override
    public void onMarkerDragStart(@NonNull Marker marker) {

    }

    @Nullable
    @Override
    public View getInfoContents(@NonNull Marker marker) {
        return null;
    }

    @Nullable
    @Override
    public View getInfoWindow(@NonNull Marker marker) {
        return null;
    }
}